/*Write a menu driven C++ program with a class for String.Write functions
1.To determine the frequency of occurence of a patticularcharacter in the string
2.Extract a new string from original string by accepting starting position and length
3.To accept any character and return the string with by removing all occurence of a character accepted
4.To make an in-place replacement of a substring w of a string by the string x.Note that w may not be of same size that of x
5.To check wheather given string is palindrome or not
*/
#include<iostream>
#include<string>
using namespace std;

class String {
public:
    String() {
        cout << "This is constructor" << endl;
    }
};

int main() {
    string str;
    int n, op, i;
    cout << "Enter the length of the string" << endl;
    cin >> n;
    
    string s;
    cout << "Enter the string" << endl;
    cin >> s;
    
    cout << "Enter the correct choice" << endl;
    do {
        cout << "1. To determine the frequency of occurrence of a particular character in the string\n"
             << "2. Extract a new string from the original string by accepting a starting position and length\n"
             << "3. To accept any character and return the string by removing all occurrences of a character accepted\n"
             << "4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of the same size as x\n"
             << "5. To check whether the given string is a palindrome or not\n"
             << "6. Exit" << endl;
        cin >> op;

        switch (op) {
            case 1: {
                int c = 0;
                char ch;
                cout << "Enter the character" << endl;
                cin >> ch;
                for (i = 0; i < n; i++) {
                    if (s[i] == ch) {
                        c++;
                    }
                }
                cout << c << endl;
                break;
            }
            case 2: {
                int pos, len;
                cout << "Enter the position and length of the new string" << endl;
                cin >> pos >> len;
                if (pos >= 0 && pos < n && pos + len <= n) {
                    cout << s.substr(pos, len) << endl;
                } else {
                    cout << "Invalid position or length" << endl;
                }
                break;
            }
            case 3: {
                char e;
                cout << "Enter a character to be eliminated: ";
                cin >> e;
                string result = "";
                for (int i = 0; i < n; i++) {
                    if (s[i] != e) {
                        result += s[i];
                    }
                }
                s = result; // Update the original string
                cout << s << endl;
                break;
            }
            case 4: {
                string w, x;
                cout << "Enter the substring to be replaced: ";
                cin >> w;
                cout << "Enter the replacement string: ";
                cin >> x;
                size_t pos = s.find(w);
                if (pos != string::npos) {
                    s.replace(pos, w.length(), x);
                } else {
                    cout << "Substring not found" << endl;
                }
                cout << s << endl;
                break;
            }
            case 5: {
                bool ispalindrome = true;
                for (i = 0; i < n / 2; i++) {
                    if (s[i] != s[n - i - 1]) {
                        ispalindrome = false;
                        break;
                    }
                }
                if (ispalindrome) {
                    cout << "It is a palindrome" << endl;
                } else {
                    cout << "It is not a palindrome" << endl;
                }
                break;
            }
        }
    } while (op != 6);

    return 0;
}