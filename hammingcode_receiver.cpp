#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    string received;

    cout << "Enter the received codeword: ";
    cin >> received;

    int n = received.length();


    vector<int> codeword(n + 1);

    for (int i = 0; i < n; i++) {
        codeword[n - i] = received[i] - '0';
    }

    
    int r = 0;
    while (pow(2, r) < n + 1) {
        r++;
    }

    cout << "\n----- Hamming Code (Receiver Side) -----\n";

    cout << "Codeword received: " << received << endl;

    cout << "Redundant bits received:\n";

    for (int i = 0; i < r; i++) {
        int position = pow(2, i);
        cout << "R" << position << " = "
             << codeword[position] << endl;
    }


    int errorPosition = 0;

    cout << "\nresults:\n";

    for (int i = 0; i < r; i++) {
        int parityPosition = pow(2, i);
        int parity = 0;

        for (int j = 1; j <= n; j++) {
            if (j & parityPosition) {
                parity ^= codeword[j];
            }
        }

        cout << "R" << parityPosition << " = " << parity << endl;

        if (parity == 1) {
            errorPosition += parityPosition;
        }
    }

    
    if (errorPosition == 0) {
        cout << "\nError is NOT present." << endl;
    }
    else {
        cout << "\nError IS present." << endl;
        cout << "Error is at position: "
             << errorPosition << endl;

    
        codeword[errorPosition] ^= 1;

        cout << "Error corrected at position "
             << errorPosition << "." << endl;
    }


    cout << "\nFinal correct codeword: ";

    for (int i = n; i >= 1; i--) {
        cout << codeword[i];
    }

    cout << endl;

   return 0;
}
/*Enter the received codeword: 10101101110

----- Hamming Code (Receiver Side) -----
Codeword received: 10101101110
Redundant bits received:
R1 = 0
R2 = 1
R4 = 1
R8 = 0

results:
R1 = 0
R2 = 1
R4 = 1
R8 = 0

Error IS present.
Error is at position: 6
Error corrected at position 6.

Final correct codeword: 10101001110*/