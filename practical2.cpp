#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    bool flag = true, err = false;
    int size;
    cout << "\n\t\n\t Enter the number of data to send: ";
    cin >> size;
    int *data = new int[size];
    cout << "\n\tEnter the data : ";
    for (int j = 0; j < size; j++)
    {
        cin >> data[j];
    }
    int ack = 1, x = 0;
    int frame[2];
    int i = 0;
    while (i <= size)
    {
        if (flag)
        {
            if (i != size)
            {
                cout << "\n\t\n-----------------------\n";
                cout << "\n\tSender's side\n";
                cout << "\n\t-----------------------\n";
                if (err)
                {
                    cout << "\n\tTimer out!!\nAcknowldegement not received\n";
                    err = false;
                }
                else
                {
                    if (i != 0)
                    {
                        cout << "\n\tAcknoledgement received: ACK" << ack << endl;
                    }
                }
                frame[0] = data[i++];
                frame[1] = ack;
                cout << "\n\tFrame send by sender: " << frame[0];
                cout << endl
                     << "\n\twith sequence number: " << frame[1] << endl;
                x = rand() % (7);
                flag = false;
            }
        }
        else
        {
            cout << "\n\t\n-----------------------\n";
            cout << "\n\tReceiver's side\n";
            cout << "\n\t-----------------------\n";
            switch (x)
            {
            case 1:
                cout << "\n\tFrame received by receiver....\n";
                cout << "\n\tFrame received is damaged...\n\n";
                err = true;
                i--;
                break;
            case 2:
                cout << "\n\tNo frame Received...\n\n";
                err = true;
                i--;
                break;
            case 3:
                cout << "\n\tData received by Receiver: " << frame[0] << endl;
                int temp;
                if (ack == 1)
                    temp = 0;
                else
                    temp = 1;
                cout << "\n\tAcknowledgement send to Sender... ACK: " << temp << endl;
                err = true;
                i--;
                break;
            default:
                cout << "\n\tData received by Receiver:" << frame[0] << endl;
                if (ack == 1)
                    ack = 0;
                else
                    ack = 1;
                cout << "\n\tAcknowledgement send to Sender... ACK" << ack << endl
                     << endl;
                break;
            }
            flag = true;
        }
    }
    cout << "\n\t\n-----------------------\n";
    cout << "\n\tSender's side\n";
    cout << "\n\t-----------------------\n";
    cout << "\n\tAcknowledgement received: ACK" << ack << endl;
    cout << "\n\tNo Frames to send...\n";
}