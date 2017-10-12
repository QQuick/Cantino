#pragma once

template <class T>
class Stack;

template <class T>
class StackElement {
    friend class Stack <T>;
    private:
        StackElement (T *payload, char const * const label):
            payload (payload),
            label (label),
            next (0),
            prev (0)
        {
        }

        T *payload;
        char const * const label;
        StackElement *next;
        StackElement *prev;
};

template <class T>
class Stack {
    public:
        int size;

        Stack ():
            size (0),
            first (0),
            last (0)
        {
        }
        
        void push (T *payload, char const * const label = "") {
            if (size++ == 0) {
                first = new StackElement <T> (payload, label);               
                last = first;
            }
            else {
                last->next = new StackElement <T> (payload, label);
                last->next->prev = last;                
                last = last->next;
            }
        }
        
        T *pop () {
            StackElement <T> *resultElement = last;
            if (size-- == 1) {
                first = 0;
                last = 0;
            }
            else {
                last = last->prev;   // May be 0
                last->next = 0;
            }
            return resultElement->payload;
        }

        T* top () {
            return last;
        }

        T* operator[] (char const * const label) {  // Assumed to always succeed
            StackElement <T> *resultElement = first;
            while (resultElement != 0 && strcmp (resultElement->label, label) != 0) {
                resultElement = resultElement->next; 
            }
            return resultElement->payload;
        }

    private:
        StackElement <T> *first;
        StackElement <T> *last;
};
