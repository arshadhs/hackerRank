#include <bits/stdc++.h>

// https://www.hackerrank.com/challenges/pangrams/problem

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    std::map<char, int> myMap;
    for (char i = 'a'; i <= 'z'; ++i) { myMap[i]++;}

    for (char i : s) {myMap[tolower(i)]--;}

    bool found = true;
    for (char i = 'a'; i <= 'z'; ++i) { if (myMap[i] > 0) found = false;}

    return (found) ? "pangram" : "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";
    cout << result << "\n";

    fout.close();

    return 0;
}
