#include <iostream>
#include <string>

using namespace std;

//43.5% 12ms
class Solution {
public:
    string reverseVowels(string s) {
        int i = nexVowelIndex(s,-1);
        int j = preVowelIndex(s,s.size());
        while(i<j){
            swap(s[i],s[j]);
            i = nexVowelIndex(s,i);
            j = preVowelIndex(s,j);
        }
        return s;
    }

private:
    int nexVowelIndex(const string &s, int index){
        index++;
        for(int i=index;i<s.size();i++)
            if(isVowel(s[i]))
                return i;
        return s.size();
    }

    int preVowelIndex(const string &s, int index){
        index--;
        for(int i=index;i>=0;i--)
            if(isVowel(s[i]))
                return i;
        return -1;
    }

    bool isVowel(char c){
        char lowerc = tolower(c);
        return lowerc=='a' || lowerc=='e'|| lowerc=='i'||lowerc=='o'||lowerc=='u';
    }
};

int main() {
    cout<<Solution().reverseVowels("hello")<<endl;
    cout<<Solution().reverseVowels("leetcode")<<endl;
    return 0;
}