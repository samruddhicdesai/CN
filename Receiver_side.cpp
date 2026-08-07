#include <iostream>
using namespace std;
int main()
{   char a[50], b[50];
    int n, i = 0, j = 0, count = 0;
    cout<<"Bit stuffing"<<endl;
    cout<<"Receiver side"<<endl;
    cout << "Enter frame length = ";
    cin >> n;
    cout << "Enter frame (0 & 1) = ";
    cin >> a;
    while (i < n)
     {
        b[j] = a[i];
      if (a[i] == '1')
            count++;
        else
            count = 0;
           if (count == 5)
        {
            i++;          
            count = 0;
        }
        i++;
        j++;
    }
    b[j] = '\0';
    cout << "De-stuffing =  " << b<<endl;
    return 0;
}