 #include <bits/stdc++.h>
 using namespace std;
 
 bool is_valid(string s, int k)
    {
        // sort(s.begin(), s.end());
        
        for (int i = 1; i < s.size(); i++)
        {
            int diff = abs(s[i - 1] - s[i]);
            cout << "dif is " << diff << endl;
            if (diff > k)
                return false;
        }
        return true;
    }
    

int main()
{
    string s = "acfgbd";

    cout << is_valid(s, 2);
    return 0;
}