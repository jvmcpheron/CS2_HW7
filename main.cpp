//Jane McPheron

//Teammates: Somayeh Najafi, Yassine Berrada, Tianyi Liang 

/*
CODE RUNNING EXAMPLES
                                                     
jvmcpheron@dyn-10-140-246-187 CS2_HW7 % ./main
Size: 0
Size: 1
Size: 2
Size: 3
Size: 4
Front element: This
Pop This
Size: 3
Front element after pop: Assignment
Pop Assignment
Size: 2
Front element after pop: Is
Size: 2
 Is Difficult !!!!%                                                                     

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
    int getSize(){
        return size;
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

    std::string pop() {
        if (!empty()) {
            std::string poppedValue = data[front];
            if (front == rear) {
                

                // If only one element is left, reset the queue
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % capacity;
            }
            size--;
            return poppedValue;
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

bool unitTest(){
        CircularQueue queue = CircularQueue(2);

    // Push some elements into the queue

    if (!queue.empty()){
        std::cerr << "Queue empty error";
    }

    std::cout << "Size: " << queue.getSize() << std::endl;
    queue.push("This");
    std::cout << "Size: " << queue.getSize() << std::endl;
    queue.push("Assignment");
    std::cout << "Size: " << queue.getSize() << std::endl;
    queue.push("Is");
    std::cout << "Size: " << queue.getSize() << std::endl;
    queue.push("Difficult");
    std::cout << "Size: " << queue.getSize() << std::endl;

    if (queue.empty()){
        std::cerr << "Queue full error";
    }
    // Display the front element
    std::cout << "Front element: " << queue.frontValue() << std::endl;

    // Pop an element
    std::string temp = queue.pop();
    if (temp != "This"){std::cerr <<"Wrong Value error";}
    std::cout << "Pop " << temp << std::endl;
    std::cout << "Size: " << queue.getSize() << std::endl;

    // Display the front element after popping
    std::cout << "Front element after pop: " << queue.frontValue() << std::endl;

    // Pop an element
    std::cout << "Pop " << queue.pop() << std::endl;
    std::cout << "Size: " << queue.getSize() << std::endl;

    // Display the front element after popping
    std::cout << "Front element after pop: " << queue.frontValue() << std::endl;    

    std::cout << "Size: " << queue.getSize() << std::endl;

    queue.push("!!!!");



    while(queue.getSize() != 0){
        std::cout << " " << queue.pop();
    }


    // Display the front element after more pushes
    return 0;
}




int main() {
    unitTest();    

}
