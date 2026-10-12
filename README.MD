DeleteItem and ShiftRight

Design and Documentation:

1.  State the invariant your DeleteItem loop maintains — what is true about the portion of the array you have already examined? Write this as a comment above the function.

-> the prefix info[0...writeIndex] contains all non-target values encountered in the for-loop info[0...readIndex] so far in their original relative ordering
-> readIndex - writeIndex indicates the number of target values seen so far
-> writeIndex indicates the number of non-target values encountered by the readIndex so far
-> 0 <= writeIndex <= readIndex

-> ReadIndex - WriteIndex indicates the number of target values seen so far
-> writeIndex indicates the number of non-target values encountered so far
-> 0 <= writeIndex <= readIndex;
-> the prefix info(0...writeIndex) contains all non-target values placed contiguously in the array in their original relative order

2.  Walk me through what your index does at the moment you delete an element. Did you traverse the list once, or more than once? What is your running time given the way you actually wrote it?


when an element is deleted (in this case overwritten), the writeIndex increments by one and the readIndex continues incrementing through the for loop up to length. I traversed the list once. The running time is O(n)

3.  Run your code on a list where every item is a 4. Then on an empty list. Show both outputs and say whether you predicted them.

Shift right on all fours – no perceptible change
Shift right on an empty list - no perceptible change

DeleteItem(4) on an all-four list – list becomes empty
DeleteItem(4) on an empty list - no perceptible change
    
I predicted these behaviors. ShiftRight returns immediately and DeleteItem skips its for-loop and sets its length to 0 (the value of 'writeIndex' in this case) upon encountering an empty list. ShiftRight technically does its shifting operation on a list of all fours, but each element is indistinguishable from the last. DeleteItem(4) on a list of all fours results in an empty list. These behaviors indicate the designs functioning as I had intended.


4. The driver calls ShiftRight on a 5-item list and then again on the 2-item list left after deletion. Show both outputs and explain how your function knew where the end was.

it is an invariant of the UnosrtedTypeArray that 'length' always accurately tracks the number of elements in a class object and length-1 indicates the index of the element. Length, or to be precise length-1, bounds the for-loop that runs inside of DeleteItem and indicates the final item.

5.  Delete a value that is not in the list. Confirm the list is unchanged, and point to the code that guarantees it.

When attempting to delete an item that is not in the list, the list remains unchange. This is true due to the nature of the for-loop that runs the read and write indices across the list: if (info[readIndex].ComparedTo(item) != EQUAL). As long as the item encountered is not the target, the read and write heads denote the same index at the beginning of each for-loop and are never offset. Thus, the write head writes to the same location the read head is pointing during every loop iteration.






random thoughts:


    --> two pointer approach – writer stops when it sees as target value; reader continues down the line until it passes the target value; once it finds the next non-target value, it copies that data to the writer's location to replace the target value. this requires basically no shifting. You end up with garbage values at the end, but the logical length of a vector (not its capacity) is constrained by the length value; it will be increased when the garbage is overwritten with important data. The Tradeoff: A capacity-shrink isn't necessary unless you do a massive delete and you don't expect to fill that storage in for a while; but C++ vectors take an opinionated stance–they never purposely shrink their size even when length drops very low; they only size up.

    --> shrink_to_fit shrinks the vector to the size of length; this can be expensive because it requires invalidating all pointers and copying remaining data to new physical memory.

“I am writing a DeleteItem function in C++ over an array-based list that must remove ALL copies of a value, not just the first. Do not write it for me. I want to understand the index bug: if I shift elements left when I find a match and then increment my index, what gets skipped and why? Show me the failure on a small example like {4, 5, 4, 4, 8}, and then describe two different ways to structure the loop so it cannot happen.”

Design and Documentation – Question 1 is submitted in the code; the rest are fairgame for Major Oral 1:

