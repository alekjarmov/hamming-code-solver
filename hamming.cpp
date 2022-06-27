// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to generate hamming code
vector<int> generateHammingCode(
    vector<int> msgBits, int m, int r)
{
    // Stores the Hamming Code
    vector<int> hammingCode(r + m);

    // Find positions of redundant bits
    for (int i = 0; i < r; ++i)
    {

        // Placing -1 at redundant bits
        // place to identify it later
        hammingCode[pow(2, i) - 1] = -1;
    }

    int j = 0;

    // Iterate to update the code
    for (int i = 0; i < (r + m); i++)
    {

        // Placing msgBits where -1 is
        // absent i.e., except redundant
        // bits all postions are msgBits
        if (hammingCode[i] != -1)
        {
            hammingCode[i] = msgBits[j];
            j++;
        }
    }

    for (int i = 0; i < (r + m); i++)
    {

        // If current bit is not redundant
        // bit then continue
        if (hammingCode[i] != -1)
            continue;

        int x = log2(i + 1);
        int one_count = 0;

        // Find msg bits containing
        // set bit at x'th position
        for (int j = i + 2;
                j <= (r + m); ++j)
        {

            if (j & (1 << x))
            {
                if (hammingCode[j - 1] == 1)
                {
                    one_count++;
                }
            }
        }

        // Generating hamming code for
        // even parity
        if (one_count % 2 == 0)
        {
            hammingCode[i] = 0;
        }
        else
        {
            hammingCode[i] = 1;
        }
    }

    // Return the generated code
    return hammingCode;
}

// Function to find the hamming code
// of the given message bit msgBit[]
void findHammingCode(vector<int>& msgBit)
{

    // Message bit size
    int m = msgBit.size();

    // r is the number of redundant bits
    int r = 1;

    // Find no. of redundant bits
    while (pow(2, r) < (m + r + 1))
    {
        r++;
    }

    // Generating Code
    vector<int> ans
        = generateHammingCode(msgBit, m, r);

        int zbir=0;
        for(int i=0;i<ans.size();i++)
        {
            zbir+=ans[i];
        }
        zbir%=2;

    // Print the code
    cout << "Podatocni bitovi se:   \t"<<" ";
    for (int i = 0; i < msgBit.size(); i++)
        cout << msgBit[i] << " ";

    cout << "\nHamingoviot kod e: \t ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
        cout<<", "<<zbir<<" e bit za parnost za L=4 ";
        cout << "\nKontrolni bitovi se: \t ";
        for(int i=0;(pow(2,i)-1)<ans.size();i++)
        {
            cout<<ans[pow(2,i)-1]<<" ";
        }
}

// Driver Code
int main()
{
    // Given message bits

    while(1)
    {
        string s;
        cout<<"Broj koj se kodira: \t"<<" ";
        cin>>s;
        vector<int> msgBit;
        for(int i=0; i<s.size(); i++)
        {
            msgBit.push_back(s[i]-'0');
        }

        // Function Call
        findHammingCode(msgBit);

        cout<<endl<<"______________________________________________________________________"<<endl;

    }


    return 0;
}
