#ifndef HEAP_H
#define HEAP_H
#include "Player.h"
#include <string>
#include <vector>

class Heap{
    private:
        std::vector<int> heap;
    public:
        Heap(std::string filename);//creates a heap by reading in players from a file
        Heap(const Heap &copy);//creates a new heap that is identical to the heap that gets passed
        void addPlayer(Player newPlayer);//adds a new player to the heap
        Player getPlayer();//returns the player with the hight priority
        bool empty();//returns true if there are no elements in the heap, otherwise returns false
        unsigned int size();//returns the number of players in the heap
        void heapify();//formats the vector into a heap
        void siftDown(int index);//performs siftDown on the passed index
};
#endif
