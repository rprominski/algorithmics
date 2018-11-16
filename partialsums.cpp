h#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

string toString( int x)
{
    stringstream ss;
    ss<<x;
    string a;
    ss>>a;
    return a;
}

string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";
    vector<int> result(n1 + n2, 0);

    int i_n1 = 0;
    int i_n2 = 0;

    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;

        for (int j=n2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';

            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            carry = sum/2;

            result[i_n1 + i_n2] = sum % 2;

            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
       return "0";

    string s = "";
    while (i >= 0)
        s += toString(result[i--]);

    return s;
}

void expand( string &s)
{
    string a="1";
    int t=s.size();
    if(s[0]=='0')
        a="0";
    for(int i=0;i<t;i++)
        s=a+s;
}

int main()
{
    int t,k;

    while(cin>>t)
    {
        string a,b;
        if(t==0)
            break;
        cin>>a>>b;
        int flag=(a[0]-'0')^(b[0]-'0');
        expand(a);
        expand(b);
        string res=multiply(a,b);
        res=res.substr(res.size()-2*t,2*t);
        while(1)
        {
            cout<<flag<<" "<<res[0]<<" "<<res[1]<<endl;

            if(flag==res[0] && flag==res[1])
                res.erase(0);
            else
                break;
        }
        cout<<res<<endl;
    }

    return 0;
}
