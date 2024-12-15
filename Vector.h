#include <iostream>
#include <cstdlib> // For std::realloc and std::free

class Vector {
    int* data;       // Pointer to the data
    size_t size;     // Current number of elements
    size_t capacity; // Capacity of the allocated memory

public:
    // Constructor
    Vector() : data(nullptr), size(0), capacity(0) {}

    // Destructor
    ~Vector() {
        std::free(data);
    }

    // push_back function to add an element to the vector
    void push_back(int value) {
        if (size == capacity) {
            // Double the capacity or set it to 1 if capacity is 0
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            resize(new_capacity);
        }
        data[size++] = value;
    }

    // Helper function to resize the storage
    void resize(size_t new_capacity) {
        int* new_data = static_cast<int*>(std::realloc(data, new_capacity * sizeof(int)));
        if (!new_data) {
            throw std::bad_alloc(); // Handle memory allocation failure
        }
        data = new_data;
        capacity = new_capacity;
    }

    // Function to get the current size of the vector
    size_t get_size() const {
        return size;
    }

    // Function to access elements by index
    int operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Function to print the vector elements (for demonstration purposes)
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};
