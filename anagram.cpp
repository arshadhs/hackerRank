// https://www.hackerrank.com/challenges/anagram/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    if (s.length()%2 != 0) return -1;
    
    string s1 = s.substr(0, s.length()/2);
    string s2 = s.substr(s.length()/2, s.length()/2);

    map<char, int> myStr;
    for (int i = 0; i < s.length()/2; i++) { myStr[s[i]]++; }
    for (int i = s.length()/2; i < s.length(); i++) if(myStr[s[i]] != 0) myStr[s[i]]--;

    int ret = 0;
    for(map<char, int>::iterator myItr = myStr.begin(); myItr != myStr.end(); myItr++)    
        ret += myItr->second;
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << "Result " << result << "\n";
        cout << "ResultC "  << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
