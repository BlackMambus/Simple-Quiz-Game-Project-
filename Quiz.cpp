#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for random shuffle
#include <random>    // for random number generation

using namespace std;

// Structure to represent a question
struct Question {
    string questionText;
    vector<string> options;
    int correctOptionIndex; // Index of the correct option (0-based)
};

// Function to display a question and get the user's answer
int askQuestion(const Question& question) {
    cout << question.questionText << endl;
    for (size_t i = 0; i < question.options.size(); ++i) {
        cout << (i + 1) << ". " << question.options[i] << endl;
    }

    int answer;
    cout << "Your answer (1-" << question.options.size() << "): ";
    cin >> answer;

    // Validate input
    while (cin.fail() || answer < 1 || answer > question.options.size()) {
        cout << "Invalid input. Please enter a number between 1 and " << question.options.size() << ": ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> answer;
    }

    return answer - 1; // Convert to 0-based index
}

int main() {
    // Seed the random number generator
    random_device rd;
    mt19937 g(rd());

    // Create a vector of questions
    vector<Question> questions = {
        {
            "What is the capital of France?",
            {"London", "Paris", "Berlin", "Rome"},
            1 // Paris
        },
        {
            "What is 2 + 2?",
            {"3", "4", "5", "6"},
            1 // 4
        },
        {
            "Which planet is known as the 'Red Planet'?",
            {"Earth", "Mars", "Jupiter", "Venus"},
            1 // Mars
        },
        {
            "What is the chemical symbol for water?",
            {"H2O", "CO2", "O2", "N2"},
            0 // H2O
        },
        {
            "Who wrote 'Hamlet'?",
            {"Charles Dickens", "William Shakespeare", "Jane Austen", "Mark Twain"},
            1 // William Shakespeare
        }
    };

    // Shuffle the questions (optional, but makes the quiz more interesting)
    shuffle(questions.begin(), questions.end(), g);

    int score = 0;

    // Iterate through the questions
    for (const auto& question : questions) {
        int userAnswer = askQuestion(question);

        if (userAnswer == question.correctOptionIndex) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect. The correct answer was: " << question.options[question.correctOptionIndex] << endl;
        }
        cout << endl; // Add a blank line for readability
    }

    // Display the final score
    cout << "Quiz complete!" << endl;
    cout << "Your score: " << score << " out of " << questions.size() << endl;

    return 0;
}




