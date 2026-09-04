#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Check if IPv4 address is valid and extract octets
bool isValid(string ip, int octet[])
{
    stringstream ss(ip);
    string part;
    int count = 0;

    while (getline(ss, part, '.'))
    {
        // More than 4 octets
        if (count >= 4 || part.empty())
            return false;

        // Check all characters are digits
        for (char ch : part)
        {
            if (!isdigit(ch))
                return false;
        }

        int num;

        try
        {
            num = stoi(part);
        }
        catch (...)
        {
            return false;
        }

        // Each octet must be between 0 and 255
        if (num < 0 || num > 255)
            return false;

        octet[count] = num;
        count++;
    }

    // IPv4 must have exactly 4 octets
    return count == 4;
}

// Convert integer array to dotted decimal string
string toDottedDecimal(int arr[])
{
    return to_string(arr[0]) + "." +
           to_string(arr[1]) + "." +
           to_string(arr[2]) + "." +
           to_string(arr[3]);
}

int main()
{
    string ip;
    int octet[4];

    cout << "Enter IPv4 address in decimal form: ";
    cin >> ip;

    // Validate IP address
    if (!isValid(ip, octet))
    {
        cout << "\nInvalid IPv4 Address!" << endl;
        return 0;
    }

    cout << "\nValid IPv4 Address!" << endl;

    int firstOctet = octet[0];

    string ipClass;
    string defaultMask;
    int networkBits;

    // Identify IP Class
    if (firstOctet >= 1 && firstOctet <= 126)
    {
        ipClass = "Class A";
        defaultMask = "255.0.0.0";
        networkBits = 8;
    }
    else if (firstOctet >= 128 && firstOctet <= 191)
    {
        ipClass = "Class B";
        defaultMask = "255.255.0.0";
        networkBits = 16;
    }
    else if (firstOctet >= 192 && firstOctet <= 223)
    {
        ipClass = "Class C";
        defaultMask = "255.255.255.0";
        networkBits = 24;
    }
    else if (firstOctet >= 224 && firstOctet <= 239)
    {
        cout << "Class: Class D" << endl;
        cout << "Used for Multicast." << endl;
        cout << "Network ID and Host ID are not applicable." << endl;
        return 0;
    }
    else
    {
        cout << "Class: Class E" << endl;
        cout << "Reserved for Experimental Use." << endl;
        cout << "Network ID and Host ID are not applicable." << endl;
        return 0;
    }

    // Arrays for Network ID and Host ID
    int netID[4] = {0, 0, 0, 0};
    int hostID[4] = {0, 0, 0, 0};

    // Calculate Network ID and Host ID according to class
    if (networkBits == 8)          // Class A
    {
        netID[0] = octet[0];

        hostID[1] = octet[1];
        hostID[2] = octet[2];
        hostID[3] = octet[3];
    }
    else if (networkBits == 16)    // Class B
    {
        netID[0] = octet[0];
        netID[1] = octet[1];

        hostID[2] = octet[2];
        hostID[3] = octet[3];
    }
    else if (networkBits == 24)    // Class C
    {
        netID[0] = octet[0];
        netID[1] = octet[1];
        netID[2] = octet[2];

        hostID[3] = octet[3];
    }

    // Display output
    cout << "\n========== OUTPUT ==========" << endl;

    cout << "\nIPv4 Address: "
         << ip << endl;

    cout << "\nIP Class: "
         << ipClass << endl;

    cout << "Default Subnet Mask: "
         << defaultMask << endl;

    // Network ID
    cout << "\nNetwork ID: "
         << toDottedDecimal(netID) << endl;

    // Host ID
    cout << "Host ID: "
         << toDottedDecimal(hostID) << endl;

    return 0;
}
/*Enter IPv4 address in decimal form: 129.45.32.3

Valid IPv4 Address!

========== OUTPUT ==========

IPv4 Address: 129.45.32.3

IP Class: Class B
Default Subnet Mask: 255.255.0.0

Network ID: 129.45.0.0
Host ID: 0.0.32.3

------------------------------------------------

Enter IPv4 address in decimal form: 233.2344.33

Invalid IPv4 Address!*/