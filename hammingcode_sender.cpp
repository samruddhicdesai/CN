#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string dataword;
    cout << "Enter the dataword: ";
    cin >> dataword;
    int m = dataword.length();
    int r = 0;
     while ((1 << r) < (m + r + 1))
    {
        r++;
    }
    int totalBits = m + r;
    vector<int> codeword(totalBits + 1, 0);
    int j = m - 1;
    for (int i = 1; i <= totalBits; i++)
    {
       if ((i & (i - 1)) != 0)
        {
            codeword[i] = dataword[j] - '0';
            j--;
        }
    }
    for (int p = 0; p < r; p++)
    {
        int parityPosition = 1 << p;
        int parity = 0;

        for (int i = 1; i <= totalBits; i++)
        {
            if ((i & parityPosition) && i != parityPosition)
            {
                parity = parity ^ codeword[i];
            }
        }

        codeword[parityPosition] = parity;
    }
    cout << "\n----- Hamming Code -----\n";

    cout << "Dataword: " << dataword << endl;

    cout << "Total number of bits in dataword: "
         << m << endl;

    cout << "Total number of redundant bits: "
         << r << endl;

    cout << "Total number of bits in codeword: "
         << totalBits << endl;
    cout << "\nRedundant bits:\n";
  for (int p = 0; p < r; p++)
    {
     int position = 1 << p;

     cout << "R" << position << " = "
             << codeword[position] << endl;
    }
   cout << "\nFinal codeword: ";

    for (int i = totalBits; i >= 1; i--)
    {
        cout << codeword[i];
    }

    cout << endl;

    return 0;
}
/*Enter the dataword: 1011

----- Hamming Code -----
Dataword: 1011
Total number of bits in dataword: 4
Total number of redundant bits: 3
Total number of bits in codeword: 7

Redundant bits:
R1 = 1
R2 = 0
R4 = 0

Final codeword: 1010101*/