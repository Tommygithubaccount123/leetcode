class Solution {
public:
    string reverseWords(string s) {
        vector<string> strings;
        int n = s.size();
        int counter = 0;
        while (counter < n){
            if (s[counter] == ' '){
                counter++;
            }
            else{
                string word;
                while(counter < n && s[counter] != ' '){
                    word += s[counter];
                    counter++;
                }
                strings.push_back(word);
            }
        }

        string output;
        for (auto word : strings){
            output = word + " " + output;
        }
        output = output.substr(0, output.size()-1);
        return output;
    }
};