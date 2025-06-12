#include <iostream>
using namespace std;

class Queues 
{
private:
    int FRONT, REAR, n = 5;
    int quenues_array[5];

public:
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // 1. cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n"; // 1.a
            return;
        }

        // 2. cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0; // 2.a
            REAR = 0; // 2.b
        }
        else
        {
            // Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max -1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        quenues_array[REAR] = num;
    }

    void remove()
    {
        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << quenues_array[FRONT] << "\n";

        //cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
    }
}