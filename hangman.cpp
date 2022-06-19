#include <stdio.h>
#include <cstdlib> 
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main()
{
    // variables
    string words[10] { "wave", "lemon", "basket", "horse", "sport", "summer", "bakery", "heart", "store", "computer"};
    string answer = words[rand() % 10 + 1];
    vector<int> foundCharIndexes;
    int foundCount = 0;
    int lives = 5;
    
    // game loop
    while (foundCount < (answer.size()-1) && lives > 0)
    {
        // number of lives
        cout << " \nYou have: " << lives << " lives left." << endl;
        
        
        foundCount = 0;
        // print out current set of letters
        for (int i = 0; i < answer.length(); ++i)
        {
            if (find (foundCharIndexes.begin(), foundCharIndexes.end(), i) != foundCharIndexes.end())
            {
                // letter has been found
                cout << answer[i] << " "; // print the char
                foundCount++; // add one to the count
            }
            else
            {
                // letter hasn't been found
                cout << "_ ";
            }
        }
        cout << endl;
                
        // get the users guess
        char userChoice = ' ';
        bool found = false;
        cout << "Choose a character" << endl;
        cin >> userChoice;
    
        // for each character in the answer string
        for (int i = 0; i < answer.length(); i++)
        {
            // if the users guess is correct
            if (userChoice == answer[i])
            {
                // say we have a correct guess
                found = true;
                foundCharIndexes.push_back (i);
            }
        }
        
        // decrease lives if appliable
        if (found == false)
            lives--;
        
    }
        
    // output game concluison
    if (lives != 0)
        cout << "\nCongrats you won!" << endl;
    else
        cout << "\nOh no, you lost :( !" << endl;

    return 0;
}