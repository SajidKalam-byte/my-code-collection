import pandas as pd
import matplotlib.pyplot as plt
from wordcloud import WordCloud


import re
import nltk
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer


# Load the dataset
sms = pd.read_csv('sms100.csv', sep='\t', names=['label', 'message'], encoding='latin-1')

# 1. Class Distribution
class_counts = sms['label'].value_counts()
print("Class Distribution:")
print(class_counts)




# 2. Message Length
sms['message_length'] = sms['message'].astype(str).apply(len)
print("\nMessage Length Statistics:")
print("Spam Messages:")
print(sms[sms['label'] == 'spam']['message_length'].describe())
print("\nHam Messages:")
print(sms[sms['label'] == 'ham']['message_length'].describe())


################################################

# Download necessary NLTK resources
nltk.download('stopwords')
nltk.download('punkt')

# Text Preprocessing
def preprocess_text(text):
    text = str(text)  # Convert to string to ensure compatibility with string methods
    text = re.sub(r'[^a-zA-Z\s]', '', text.lower())

    # Tokenization
    tokens = nltk.word_tokenize(text)

    # Stop word removal
    stop_words = set(stopwords.words('english'))
    tokens = [word for word in tokens if word not in stop_words]

    # Stemming
    stemmer = PorterStemmer()
    stemmed_tokens = [stemmer.stem(token) for token in tokens]

    return ' '.join(stemmed_tokens)

# Vectorization
def vectorize_text(texts, method='count'):
    if method == 'count':
        vectorizer = CountVectorizer()
    elif method == 'tfidf':
        vectorizer = TfidfVectorizer()
    else:
        raise ValueError("Invalid vectorization method. Choose 'count' or 'tfidf'.")

    X = vectorizer.fit_transform(texts)
    return X, vectorizer  # Return the vectorizer here

# Example usage
sms_data = ['This is a sample text message.', 'Hello, how are you doing?', 'Free money! Win big prizes!']

preprocessed_texts = [preprocess_text(text) for text in sms_data]
print('Preprocessed texts:', preprocessed_texts)

X, vectorizer = vectorize_text(preprocessed_texts, method='count')  # Example usage
print('Count vectors:\n', X.toarray())

X, vectorizer = vectorize_text(preprocessed_texts, method='tfidf')  # Example usage
print('TF-IDF vectors:\n', X.toarray())

# Preprocess all messages
sms['preprocessed_message'] = sms['message'].apply(preprocess_text)

# Vectorize preprocessed messages
X, vectorizer = vectorize_text(sms['preprocessed_message'], method='tfidf')  # Example usage
X = X.toarray()

# Use 'label' column as target labels
y = sms['label'].values

########################################

from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
from sklearn.preprocessing import StandardScaler

# Assume 'X' is your numerical feature matrix and 'y' is the target labels

# Split data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Scale the features (recommended for SVM)
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Train the SVM classifier
svm = SVC(kernel='linear', probability=True)  # Set probability=True for precision-recall
svm.fit(X_train, y_train)

# Make predictions on the testing set
y_pred = svm.predict(X_test)

# Evaluate the classifier's performance
accuracy = accuracy_score(y_test, y_pred)
precision = precision_score(y_test, y_pred, pos_label='spam')
recall = recall_score(y_test, y_pred, pos_label='spam')
f1 = f1_score(y_test, y_pred, pos_label='spam')

print("Accuracy:", accuracy)
print("Precision:", precision)
print("Recall:", recall)
print("F1-score:", f1)
# Define a custom scorer, specifying 'spam' as the positive label
from sklearn.metrics import make_scorer, f1_score
f1_scorer = make_scorer(f1_score, pos_label='spam')

# Use the Custom Scorer in GridSearchCV
from sklearn.model_selection import GridSearchCV
from sklearn.svm import SVC

# Define parameter grid for GridSearchCV
param_grid = {
    'C': [0.1, 1, 10, 100],  # Example values for C
    'kernel': ['linear', 'rbf']  # Example kernel types
}

# Assuming 'svm' is your SVC model
grid_search = GridSearchCV(svm, param_grid, cv=5, scoring=f1_scorer, n_jobs=4)
grid_search.fit(X_train, y_train)

# Extracting coefficients for feature importance
# Assuming 'vectorizer' is your TfidfVectorizer or CountVectorizer instance
# and 'svm' is your trained linear SVM model

# Get feature names
feature_names = vectorizer.get_feature_names_out()

# Get the coefficients from the model
coefficients = svm.coef_.flatten()

# Create a dictionary mapping each word to its coefficient
coefficients_dict = {word: coeff for word, coeff in zip(feature_names, coefficients)}

print(coefficients_dict)
