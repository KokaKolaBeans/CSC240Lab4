Project Specifications:

1.  Using Array-Based Unsorted Type (handling ints)
2.  DeleteItem must remove ALL copies of items

    Update the specifications of the DeleteItem function of the array-based version of UnsortedType as follows:

        If the ItemType to be deleted is not found in the list, the list remains unchanged.
        All copies of the item to be deleted are removed from the list, if they exist.

    --> Pointers begin and end that always point to the beginning and end of the list
    begin() and end() return iterators

    --> create pointer iterator that can traverse the list
    --> std:: vector attributes
    v.size() - returns number of elements in the vector // O(c)
    v.capacity() - returns current capacity of storage space allocated for the vector, expressed in terms of elements // O(c)

    --> std::vector has the following functionality:
    v.resize();
    void resize (size_type n, value_type val = value_type()); // O(n), where n is the number of elements added

            if n is less than number of current elements e, elements at positions e > n are destroyed; capacity is untouched
            if n > elements, new elements are inserted at the end to reach size n using default constructor; if val is specified, added values are copies of val
            if n > capacity, more capacity is automatically allocated

            If the container expands, the end iterator is invalidated and, if it has to reallocate storage, all iterators, pointers and references related to this container are also invalidated.

    --> General syntax:

        std::vector v{0, 1, 2, 3, 4, 5};

        void printLength(const std::vector<int>& v)

    --> implementation of Delete // O(n^2) 1. Only increment index pointer when you don't find a match–if you find a match, you must delete, then avoid moving the iterator 2. Iterator backwards

    --> two pointer approach – writer stops when it sees as target value; reader continues down the line until it passes the target value; once it finds the next non-target value, it copies that data to the writer's location to replace the target value. this requires basically no shifting. You end up with garbage values at the end, but the logical length of a vector (not its capacity) is constrained by the length value; it will be increased when the garbage is overwritten with important data. The Tradeoff: A capacity-shrink isn't necessary unless you do a massive delete and you don't expect to fill that storage in for a while; but C++ vectors take an opinionated stance–they never purposely shrink their size even when length drops very low; they only size up.

    --> shrink_to_fit shrinks the vector to the size of length; this can be expensive because it requires invalidating all pointers and copying remaining data to new physical memory.

    // 1. Allocate a brand new array sized exactly for the survivors
    int\* newArray = new int[newSize];

    // 2. Copy only the surviving elements over from the old array
    for (int i = 0; i < newSize; i++) {
    newArray[i] = oldArray[i];
    }

    // 3. Destroy the old, bloated array to free the RAM
    delete[] oldArray;

    // 4. Update your class variables to point to the new, tight array
    oldArray = newArray;
    capacity = newSize;

    --> consider alt syntax for 'for':

    for (string car : cars)
    {
    cout << car << "\n";
    }

3.  Must implement ShiftRight. Every element moves one space right, and the item at the end wraps around to move to the front

    Create a function called ShiftRight that shifts the contents of the list one index to the right, bringing the last item (index = length - 1) to the front (index = 0).

Test List: {4, 5, 4, 4, 8}

None — you continue from your own Lab 3 work. Part B of Lab 3 had you write the array-based UnsortedType from scratch. That class, with your ItemType, is what this lab modifies. Copy your Lab 3 array implementation into a new folder and work there, so your Lab 3 submission stays intact.

AI Learning Query:

“I am writing a DeleteItem function in C++ over an array-based list that must remove ALL copies of a value, not just the first. Do not write it for me. I want to understand the index bug: if I shift elements left when I find a match and then increment my index, what gets skipped and why? Show me the failure on a small example like {4, 5, 4, 4, 8}, and then describe two different ways to structure the loop so it cannot happen.”

Design and Documentation – Question 1 is submitted in the code; the rest are fairgame for Major Oral 1:

1. State the invariant your DeleteItem loop maintains — what is true about the portion of the array you have already examined? Write it as a comment above the function. (Graded under Design and Documentation.)

2. Walk me through what your index does at the moment you delete an element. Did you traverse the list once, or more than once? What is your running time given the way you actually wrote it?

3. Run your code on a list where every item is a 4. Then on an empty list. Show both outputs and say whether you predicted them.

4. The driver calls ShiftRight on a 5-item list and then again on the 2-item list left after deletion. Show both outputs and explain how your function knew where the end was.

5. Delete a value that is not in the list. Confirm the list is unchanged, and point to the code that guarantees it.
