#include <iostream>
#include <string>
using namespace std;

string divide(string data, string key)
{
    int n = key.length();

    for (int i = 0; i <= data.length() - n; i++)
    {
        if (data[i] == '1')
        {
            for (int j = 0; j < n; j++)
            {
                data[i + j] = (data[i + j] == key[j]) ? '0' : '1';
            }
        }
    }

    return data.substr(data.length() - n + 1);
}

int main()
{
    string data, key;

    cout << "Enter data: ";
    cin >> data;

    cout << "Enter generator: ";
    cin >> key;

    int zeros = key.length() - 1;

    string appendedData = data + string(zeros, '0');

    string crc = divide(appendedData, key);

    string transmittedData = data + crc;

    cout << "\nNumber of extra 0 bits added: " << zeros << endl;
    cout << "Data after adding 0 bits: " << appendedData << endl;
    cout << "CRC bits / reminder: " << crc << endl;
    cout << "Transmitted data: " << transmittedData << endl;

    return 0;
}
/*Enter data: 10100001
Enter generator: 1001

Number of extra 0 bits added: 3
Data after adding 0 bits: 10100001000
CRC bits / reminder: 111
Transmitted data: 10100001111*/