#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
#include <algorithm>  // Required for remove_if and transform

using namespace std;

// Function to read the file and return the content as a string
string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return "";
    }

    stringstream buffer;
    buffer << file.rdbuf();  // Read the entire file into a stringstream
    file.close();
    return buffer.str();
}

// Function to count words in a given string
int wordCount(const string& text) {
    istringstream stream(text);
    int count = 0;
    string word;

    while (stream >> word) {
        count++;
    }

    return count;
}

// Function to count characters in the text (excluding spaces, tabs, and newlines)
int characterCount(const string& text) {
    int count = 0;

    for (char ch : text) {
        if (!isspace(ch)) {
            count++;
        }
    }

    return count;
}

// Function to analyze word frequency
map<string, int> wordFrequency(const string& text) {
    map<string, int> freq;
    string word;
    istringstream stream(text);

    while (stream >> word) {
        // Remove punctuation from word
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        // Convert word to lowercase for case-insensitive comparison
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        freq[word]++;
    }

    return freq;
}

// Function to display the analytics
void displayAnalytics(const string& text) {
    int words = wordCount(text);
    int characters = characterCount(text);
    map<string, int> freq = wordFrequency(text);

    // Display word and character count
    cout << "Total Words: " << words << endl;
    cout << "Total Characters (excluding spaces): " << characters << endl;
    cout << "Word Frequency:\n";

    // Display the word frequency
    for (const auto& pair : freq) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    string filename;
    // Ask user for the filename
    cout << "Enter the name of the text file (with extension): ";
    cin >> filename;

    // Read the file
    string text = readFile(filename);

    if (text.empty()) {
        return 1;  // Exit if file couldn't be read
    }

    // Display the text analytics
    displayAnalytics(text);

    return 0;  // Exit successfully
}
