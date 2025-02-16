class Solution {
    public:
        string backspace(string s) {
            bool foundBackspace = false;
    
            vector<int> deleted(s.length() + 5, false);
            while (true) {
                for (int i = 0; i < s.length(); i++) {
                    if (deleted[i]) continue;
                    if (s[i] == '#') {
                        foundBackspace = true;
                        deleted[i] = true;
                        for (int j = i; j >= 0; j--) {
                            if (deleted[j]) continue;
                            if (s[j] != '#') {
                                deleted[j] = true;
                                break;
                            }
                        }
                    }
                }
    
                if (foundBackspace == false) break;
                foundBackspace = false;
            }
    
            string result;
            for (int i = 0; i < s.length(); i++) {
                if (deleted[i]) continue;
                result += s[i];
            }
    
            return result;
        }
        bool backspaceCompare(string s, string t) {
            cout << backspace(s) << "\n" << backspace(t);
            return (backspace(s) == backspace(t));
        }
    };