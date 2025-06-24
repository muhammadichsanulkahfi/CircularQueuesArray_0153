/** 
 * @mainpage Documentation Circular Queues
 * 
 * @section Introduction
 * Perojet ini merupakan projek struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section Operations
 * Peroject ini memeiliki beberapa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 
 * @section cara pengguna
 * Berikut beberapa menu yang bisa digunakan: 
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profil
 * - nama : {Muhammad ikhsanul kahfi}
 * - nim : {20240140153}
 * - kelas :{c}
 * 
 * @brief
 * @version 1.0
 * @date 2025-06-24
 * 
 * @copyright {ikhsanul.kahfi.ft@mail.umy.ac.id} 2025
 * 
 * */
#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queus
 * 
 * 
 */
class Queues 
{
private:
    static const int max = 5;///< variable private front untuk menyimpan posisi depan antrian
    int FRONT, REAR, n = 5;///< variabel private rear untuk meyimpan posisi belakang antrian
    int queue_array[5];///< variabel private max untuk meyimpan ukuran maximum antrian
                      
public:
     /**
      * @brief constructor a new Queues object
      * set default queues null
      * with front = -1 and rear = -1
      */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memeasukkan data dalam antrian
     * data dimasukkan dalam variabel queue_array
     */
    void insert()
    {
        int num;///< variabel num untuk menyimpan nilai
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //1. Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n"; //1.a
            return;                       //1.b
        }

        //2. Cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0; // 2.a
            REAR = 0; // 2,b
        }
        else
        {
            // Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    /**
     * @brief method untuk menghapus data dalam antrian
     * data dihapuskan dalam variabel queue_array
     */
    void remove()
    {
        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";
        
        // Cek jika antrian hanya memillliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // Jika elemen yang dihapus berada diposisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

     /**
     * @brief method untuk menampilkan data dalam antrian
     * data ditampilkan yang berada dalam  variabel queue_array
     */
    void display()
    {
        int FRONT_position = FRONT;///< variabel front_position untuk menandakan posisi element
        int REAR_position = REAR;///< 

        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        /// Jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else 
        {
            // Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }

            FRONT_position = 0;

            while(FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }

}; 

/**
 * @brief method utama untuk menjalankan program
 * 
 * @return int
 */
int main() 
{
    Queues q;///< objek untuk menggunakan member yang ada pada class queues
    char ch;///< variabel ch untuk meyimpan pilihan pada menu yang di berikan

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display value" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter youy choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {

                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        { 
            cout << "Check for the values entered." << endl;
        }
    }    
 
}