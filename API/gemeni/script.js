import readline from 'readline';
import { GoogleGenerativeAI } from '@google/generative-ai';
import dotenv from 'dotenv';
dotenv.config();

// Access your API key from environment variables
const apiKey = process.env.GOOGLE_API_KEY;
if (!apiKey) {
  throw new Error("API_KEY is not set in the environment variables.");
}

const genAI = new GoogleGenerativeAI(apiKey);

async function main() {
  const userInterface = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  userInterface.prompt();

  userInterface.on('line', async (input) => {
    try {
      // Get the generative model
      const model = genAI.getGenerativeModel({ model: "gemini-1.5-flash" });

      // Generate content based on user input
      const result = await model.generateContent(input);
      const response = await result.response;
      const text = await response.text();

      console.log(text);
    } catch (error) {
      console.error("Error:", error);
    } finally {
      userInterface.prompt();
    }
  });
}

main(); // Call the main function to start execution
