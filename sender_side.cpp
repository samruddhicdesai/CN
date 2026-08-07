#include <iostream>
using namespace std;
int main()
{   char a[25], b[25];
    int n, i, j, count = 0;
    cout<<"Bit stuffing"<<endl;
    cout<<"Sender side "<<endl;
    cout << "Enter frame length = ";
    cin >> n;
    cout << "Enter frame (0 & 1) = ";
    cin >> a;
    i = 0;
    j = 0;
    while (i < n)
     {  b[j] = a[i];
        if (a[i] == '1')
            count++;
        else
            count = 0;
       if (count == 5)
        {   j++;
            b[j] = '0';
            count = 0;
            }
        i++;
        j++;
    }
      b[j] = '\0';
      cout << "Frame after Bit Stuffing = " << b<<endl;
      return 0;
}
    
