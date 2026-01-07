#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/*
 * Algorithm Challenge & Problem Solving Level 3 – Challenge #31 Count Letter Occurrences (Match Case or Ignore Case)
 *
 * This program reads a string and a character from the user, then counts how many times the character appears in the string:
 * - With case sensitivity (default behavior)
 * - Without case sensitivity (ignoring letter case)
 *
 * The challenge focuses on:
 * - Case-sensitive vs case-insensitive algorithms
 * - Optional parameters (default arguments)
 * - Character normalization
 * - Writing flexible and configurable functions
 */

// Reads a full string from the user
string ReadString()
{
    string Text;
    cout << "Enter a string:\n";
    getline(cin, Text);
    return Text;
}

// Reads a single character to be counted
char ReadChar()
{
    char Char1;
    cout << "Enter a character to count:\n";
    cin >> Char1;
    return Char1;
}

// Inverts the case of a character (upper <-> lower)
char InvertLetter(char Ch1)
{
    return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);
}

// Counts character occurrences with optional case sensitivity
short CountLetter(string S1, char Ch1, bool MatchCase = true)
{
    short Counter = 0;

    for (int i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            // Case-sensitive comparison
            if (S1[i] == Ch1)
                Counter++;
        }
        else
        {
            // Case-insensitive comparison
            if (tolower(S1[i]) == tolower(Ch1))
                Counter++;
        }
    }

    return Counter;
}

int main()
{
    string S1 = ReadString();
    char Ch1 = ReadChar();

    cout << "\nMatch Case Letter '" << Ch1 << "' Count = "
         << CountLetter(S1, Ch1) << endl;

    cout << "Ignore Case Letter '" << Ch1
         << "' or '" << InvertLetter(Ch1)
         << "' Count = "
         << CountLetter(S1, Ch1, false) << endl;

    return 0;
}
