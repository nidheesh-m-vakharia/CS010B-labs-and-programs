#ifndef INTVECTOR_H
#define INTVECTOR_H


class IntVector {
    private:
        unsigned _size;                                  // number of existing elements
        unsigned _capacity;                              // total allowed elements before realocation
        int *_data;                                 // Array holding data

    public:
        // Constructor
        IntVector();
        IntVector(unsigned capacity);
        IntVector(unsigned capacity ,int value);

        //Destructor
        ~IntVector();

        //Accesors
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;

        const int & at(unsigned index) const;
        int & at(unsigned index);

        const int & front() const;
        int & front();

        const int & back() const;
        int & back();

        //Modifiers

        void assign(unsigned n, int value);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned n, int value = 0);
        void reserve(unsigned n);
        void insert(unsigned index, int value);
        void erase(unsigned index);

};

#endif