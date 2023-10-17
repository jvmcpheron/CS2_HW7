//Jane McPheron

//Teammates: Somayeh Najafi, Yassine Berrada, Tianyi Liang 

/*
CODE RUNNING EXAMPLES

./main
Front element: Apple
Front element after pop: Banana
Front element after more pushes: Banana
jvmcpheron@dyn-10-140-246-187 CS2_HW7 % 
*/

#include <iostream>
#include <string>

class CircularQueue {
private:
    std::string *data;
    int front, rear, size, capacity;

public:
    CircularQueue(int initialSize = 10) : data(new std::string[initialSize]), front(-1), rear(-1), size(0), capacity(initialSize) {}

    ~CircularQueue() {
        delete[] data;
    }

    bool empty() const {
        return size == 0;
    }

    void push(const std::string &value) {
        if (size == capacity) {


            // Double the size of the array when it becomes full
            int newCapacity = capacity * 2;
            std::string *newData = new std::string[newCapacity];



            // Copy elements to the new array
            for (int i = 0; i < size; i++) {
                newData[i] = data[(front + i) % capacity];
            }

            delete[] data;
            data = newData;
            front = 0;
            rear = size - 1;
            capacity = newCapacity;
        }

        if (empty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        data[rear] = value;
        size++;
    }

    void pop() {
        if (!empty()) {
            if (front == rear) {


                // If only one element is left, reset the queue
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % capacity;
            }
            size--;
        }else{
            std::cerr << "You're trynna pop an empty queue buddy. Get help.";
        }
    }

    std::string frontValue() const {
        if (!empty()) {
            return data[front];
        }
        throw std::runtime_error("Queue is empty");
    }
};






int main() {
    CircularQueue queue;

    // Push some elements into the queue
    queue.push("This");
    queue.push("Assignment");
    queue.push("Is");
    queue.push("Difficult");

    // Display the front element
    std::cout << "Front element: " << queue.frontValue() << std::endl;

    // Pop an element
    queue.pop();

    // Display the front element after popping
    std::cout << "Front element after pop: " << queue.frontValue() << std::endl;

    // Push more elements to demonstrate the circular behavior
    queue.push("Elderberry");
    queue.push("Fig");


    // Display the front element after more pushes
    std::cout << "Front element after more pushes: " << queue.frontValue() << std::endl;

    return 0;
}
