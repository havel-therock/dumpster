// You are given a class called Sentence , which takes a string such as "hello world". You need to provide an interface
// such that the indexer (operator [] ) returns a WordToken  that can be used to capitalize a particular word in the
// sentence.

// Typical use would be something like :

// Sentence sentence("hello world");
// sentence[1].capitalize = true;
// cout << sentence.str(); // prints "hello WORLD"

#include <cctype>
#include <string>
#include <vector>

using namespace std;

struct Sentence {


    struct WordToken {
        bool capitalize;
        string word;
    };

    vector<WordToken> tokenized_text;

    Sentence(const string& text)
    {
        WordToken w;
        string s = "";
        for (auto ch : text) {
            if (ch != ' ') {
                s += ch;
            } else {
                w.word = s;
                tokenized_text.push_back(w);
                s = "";
            }
        }
        w.word = s;
        tokenized_text.push_back(w);
    }

    WordToken& operator[](size_t index) { return tokenized_text[index]; }

    string str() const
    {
        string out = "";
        for (auto& word : tokenized_text) {
            if (word.capitalize) {
                for (auto ch : word.word) {
                    out += toupper(ch);
                }
            } else {
                out += word.word;
            }
            out += " ";
        }
        out.pop_back();

        return out;
    }
};
