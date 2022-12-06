class Solution {
public:
    int lengthOfLastWord(string s) {
        int indexEnd = s.size() - 1;
        while(indexEnd >= 0){
            if (s[indexEnd] == ' '){
                indexEnd--;
            }
            else {
                break;
            }
        }
        int newIndex = indexEnd;
        int count = 0;
        for (int i=newIndex; i>=0; i--){
            if (s[i] == ' '){
                break;
            }
            count++;
        }
        return count;
    }
};