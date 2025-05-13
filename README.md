# Hangman Game (C++)

This is a simple implementation of the classic **Hangman** game in C++.  
🎓 This project was created as part of a university course.

## ⚙️ Requirements

- C++ compiler (e.g., g++, MSVC)
- `words` file in the `C:\` directory with a list of possible words (one per line)

## 🗂️ Project Files

hangman-cmd-game/  
├── Hangman-Console-Game/  
│ └── Hangman-Console-Game.cpp # Complete game  
└── documentation.pdf # Documentation of the project in polish

## 🚀 How to Run

1. Compile the program:
   ```bash
   g++ -o hangman Hangman-Console-Game.cpp

2. Make sure you have a `words` file at `C:\words` with appropriate content.

3. Run the program:
   ```bash
   ./hangman

## 📝 How It Works
- The program randomly selects a word from a text file named `words` located in the `C:\` directory.
- The player then attempts to guess the hidden word by typing a letter and pressing **ENTER**.
- If the letter exists in the word, the program reveals all positions of that letter.
- If the letter is not found, the number of strikes increases.
- The game allows up to **10 incorrect guesses (strikes)**.
- The game ends:
  - With **victory** if the player guesses all the letters correctly.
  - With **defeat** if the number of strikes reaches 10.

![1](https://github.com/user-attachments/assets/05aa58bf-c74b-4f18-b9d7-40c1c0e17019)
![2](https://github.com/user-attachments/assets/3a086d33-348c-4ee2-8938-02dfcc91bde9)
![3](https://github.com/user-attachments/assets/0e4ed961-f2f6-4d96-8fe2-0c0779608144)
![4](https://github.com/user-attachments/assets/6b281853-fe2b-4f16-a667-2caddaef3279)
