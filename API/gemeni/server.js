import express from 'express';
import session from 'express-session';
import { GoogleGenerativeAI } from '@google/generative-ai';
import dotenv from 'dotenv';
dotenv.config();

const app = express();
const port = process.env.PORT || 3000;

// Access your API key from environment variables
const apiKey = process.env.GOOGLE_API_KEY;
if (!apiKey) {
    throw new Error("API_KEY is not set in the environment variables.");
}

const genAI = new GoogleGenerativeAI(apiKey);

// Middleware to parse JSON bodies and handle sessions
app.use(express.json());
app.use(session({
    secret: 'your-secret-key',
    resave: false,
    saveUninitialized: true
}));

// Serve static files from the "public" directory
app.use(express.static('public'));

// User authentication route
app.post('/login', (req, res) => {
    const { username } = req.body;
    if (username) {
        req.session.username = username;
        req.session.chatHistory = [];
        res.json({ success: true, username });
    } else {
        res.status(400).json({ success: false, message: 'Username is required' });
    }
});

// Generate response from AI
app.post('/generate', async (req, res) => {
    if (!req.session.username) {
        return res.status(401).json({ error: 'Unauthorized' });
    }

    const userInput = req.body.input;
    if (!userInput) {
        return res.status(400).json({ error: 'User input is required' });
    }

    try {
        // Construct the conversation history to provide context
        const conversationHistory = req.session.chatHistory.map(msg => `${msg.role}: ${msg.content}`).join('\n');
        const prompt = `${conversationHistory}\nuser: ${userInput}`;

        // Get the generative model
        const model = genAI.getGenerativeModel({ model: "gemini-1.5-flash" });

        // Generate content based on the user input and conversation history
        const result = await model.generateContent(prompt);
        const response = await result.response;
        const text = await response.text();

        // Store the conversation in the session
        const message = { role: 'user', content: userInput };
        const aiResponse = { role: 'ai', content: text };
        req.session.chatHistory.push(message);
        req.session.chatHistory.push(aiResponse);

        res.json({ response: text });
    } catch (error) {
        console.error("Error:", error);
        res.status(500).json({ error: error.message });
    }
});

app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});
