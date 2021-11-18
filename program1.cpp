#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int i, j, k, l;

void division(int temp[], int gen_f[], int gen_size, int ds)
{
    for (i = 0; i < ds; i++)
    {
        j = 0;
        k = i;
        //check whether it is divisible or not
        if (temp[k] >= gen_f[j])
        {
            for (j = 0, k = i; j < gen_size; j++, k++)
            {
                if ((temp[k] == 1 && gen_f[j] == 1) || (temp[k] == 0 && gen_f[j] == 0))
                {
                    temp[k] = 0;
                }
                else
                {
                    temp[k] = 1;
                }
            }
        }
    }
}

int main()
{
    int ds;
    cout << "\n\t ENTER SIZE OF DATA  : ";
    cin >> ds;

    int d[20];
    cout << "\n\t ENTER DATA :";
    for (i = 0; i < ds; i++)
    {
        cin >> d[i];
    }
    //Get Generator
    int gen_size;
    int gen_f[] = {1, 1, 0, 1}; // x^3+x^2+1
    gen_size = sizeof(gen_f) / sizeof(gen_f[0]);
    cout << "\n \t <-------------------- SENDER SIDE-------------------->";
    //Append 0
    int zeroes = gen_size - 1;
    cout << "\n\t O's TO BE APPENDED : " << zeroes;
    for (i = ds; i < ds + zeroes; i++)
    {
        d[i] = 0;
    }
    int temp[20];
    for (i = 0; i < 20; i++)
    {
        temp[i] = d[i];
    }
    cout << "\n\t MESSAGE AFTER APPENDING 0's :";
    for (i = 0; i < ds + zeroes; i++)
    {
        cout << temp[i];
    }
    division(temp, gen_f, gen_size, ds);

    int crc[15];
    for (i = 0, j = ds; i < zeroes; i++, j++)
    {
        crc[i] = temp[j];
    }

    cout << "\n\t TRANSMITTED DATA : ";
    int tf[15];
    for (i = 0; i < ds; i++)
    {
        tf[i] = d[i];
    }
    for (i = ds, j = 0; i < ds + zeroes; i++, j++)
    {
        tf[i] = crc[j];
    }
    for (i = 0; i < ds + zeroes; i++)
    {
        cout << tf[i];
    }

    int n = rand() % (gen_size + ds + 5);
    tf[n] = !tf[n];
    cout << "\n\t <-----------------Receiver side-------------------->";
    cout << "\n\t RECIEVED DATA : ";
    for (i = 0; i < ds + zeroes; i++)
    {
        cout << tf[i];
    }
    for (i = 0; i < ds + zeroes; i++)
    {
        temp[i] = tf[i];
    }
    division(temp, gen_f, gen_size, ds);
    cout << "\n\t REMAINDER : ";
    int remainder[15];
    for (i = ds, j = 0; i < ds + zeroes; i++, j++)
    {
        remainder[j] = temp[i];
    }
    for (i = 0; i < zeroes; i++)
    {
        cout << remainder[i];
    }
    int flag = 0;
    for (i = 0; i < zeroes; i++)
    {
        if (remainder[i] != 0)
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << " \n\t RECIEVED MESSAGE IS CORRECT ....";
    }
    else
    {
        cout << "\n\t RECIEVED MESSAGE IS CORRUPTED WITH ERRORS.... ";
    }
}