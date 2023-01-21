#ifndef ARRAYBAG_H
#define ARRAYBAG_H

template<class T>
class ArrayBag 
{
    private:
        T* arr;
        int size;
        static const int MAX_SIZE = 1000;
    public:
        ArrayBag() {
            arr = new T[MAX_SIZE];
            size = 0;
        }
        ~ArrayBag() {
            delete [] arr;
        }
        int getSize() {
            return size;
        }
        bool isEmpty() {
            return arr == 0;
        }
        bool isFull() {
            return size == MAX_SIZE; 
        }
        bool add(T param) {
            if (!(isFull())) { // if not full
                arr[size] = param; // add to end then increment size
                size++;
                return true;
            } else 
                return false;
        }
        bool remove() {
            if (!(isEmpty())) { // if not empty decrement size
                size--;
                return true;
            } else 
                return false;
        }
        bool contains(T param) {
            for(int i = 0; i < size; i++){ // loop array
                if(arr[i] == param) // if param matches element in array
                    return true;
            }
            return false;
        }
        void makeEmpty() {
            size = 0;
        }
        void printElements() {
            for(int i = 0; i < size; i++)
                std::cout << arr[i] << std::endl;
        }
};

#endif