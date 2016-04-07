#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <climits> 
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Heap.h"
#include "Table.h"
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Heap.h"
#include "Table.h"
using namespace std;

bool verifyHeap(Heap heap){
	int value = 1000;
	while(heap.size() > INT_MAX){
		Player p = heap.getPlayer();
		int next_value = p.getBudget();
		if(next_value > value)
			return false;
		else
			value = next_value;
	}
	return true;
}

// Returns true if arr[i..n-1] represents a max-heap
bool isHeap(vector<Player> arr, int i){
	if(arr.size() <= 1 || i >= (arr.size() - 2)/2)
       return true;
   if (arr.at(i).getBudget() >= arr.at((2*i) + 1).getBudget()  &&  
   		arr.at(i).getBudget() >= arr.at((2*i) + 2).getBudget() &&
       	isHeap(arr, 2*i + 1) && isHeap(arr, 2*i + 2))
       return true;

   return false;
}

int main(){
	std::srand ( unsigned ( std::time(0) ) );

	cerr << "\n\tTEST #1: Missing file handled" << endl;
	Heap test1("empty.txt");
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #1: Create Players and store them in a heap" << endl;
	Heap tourney("players.txt");
	assert(isHeap(tourney.getArray(), 0));
	assert(tourney.size() == 17);
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #2: Players stored in correct order when removed from the heap" << endl;
	
#if 0
	while(!tourney.empty()){
			Player p = tourney.getPlayer();
			cout << "\tp = tourney.getPlayer();" << endl;
			cout << "\tassert(p.getName()==\"" << p.getName() << "\");" << endl;
	}
#else

	Player 	p = tourney.getPlayer();
	assert(p.getName()=="Chuck Norris");
	p = tourney.getPlayer();
	assert(p.getName()=="James Bond");
	p = tourney.getPlayer();
	assert(p.getName()=="Batman");
	p = tourney.getPlayer();
	assert(p.getName()=="Lara Croft");
	p = tourney.getPlayer();
	assert(p.getName()=="Tyler Durden");
	p = tourney.getPlayer();
	assert(p.getName()=="James T Kirk");
	p = tourney.getPlayer();
	assert(p.getName()=="Ellen Ripley");
	p = tourney.getPlayer();
	assert(p.getName()=="Josey Wales");
	p = tourney.getPlayer();
	assert(p.getName()=="Sarah Connor");
	p = tourney.getPlayer();
	assert(p.getName()=="Indiana Jones");
	p = tourney.getPlayer();
	assert(p.getName()=="Dirty Harry");
	p = tourney.getPlayer();
	assert(p.getName()=="Rocky Balboa");
	p = tourney.getPlayer();
	assert(p.getName()=="Snake Plissken");
	p = tourney.getPlayer();
	assert(p.getName()=="John McClane");
	p = tourney.getPlayer();
	assert(p.getName()=="John Rambo");
	p = tourney.getPlayer();
	assert(p.getName()=="Han Solo");
	p = tourney.getPlayer();
	assert(p.getName()=="Ash Williams");
#endif
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #3: Heap is empty" << endl;
	assert(tourney.empty());
	cerr << "\n\t========================PASS========================\n" << endl;


	cerr << "\n\tTEST #4: Can add individual players to the heap" << endl;
	Heap heap_test("players.txt");
	while(!heap_test.empty()){
		tourney.addPlayer(heap_test.getPlayer());
	}
	assert(verifyHeap(tourney));
	assert(isHeap(tourney.getArray(), 0));
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #5: Play 1 round of highcard" << endl;
	int ante = 5;
	Table highcardTable(5, ante);
	while(highcardTable.emptySeat()){
		highcardTable.addPlayer(tourney.getPlayer());
	}
	assert(verifyHeap(tourney));
	assert(isHeap(tourney.getArray(), 0));
	vector<Player> losers = highcardTable.playRound();
	for(auto p: losers)
		tourney.addPlayer(p);
	assert(verifyHeap(tourney));
	assert(isHeap(tourney.getArray(), 0));
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #6: Play highcard tournament" << endl;
	while(!tourney.empty()){
		while(!tourney.empty() && highcardTable.emptySeat()){
			highcardTable.addPlayer(tourney.getPlayer());
		}
		assert(verifyHeap(tourney));
		assert(isHeap(tourney.getArray(), 0));
		vector<Player> loser = highcardTable.playRound();
		for(auto p: loser){
			if(p.getBudget() > ante){
				tourney.addPlayer(p);
			}
		}
		assert(verifyHeap(tourney));
		assert(isHeap(tourney.getArray(), 0));
	}

	highcardTable.printWinner();

	cerr << "\n\t========================PASS========================\n" << endl;

	Heap tourney2("players2.txt");
	Table highcardTable2(5, ante);
	cerr << "\n\tTEST #7: Play highcard tournament with equal starting budgets" << endl;
	while(!tourney2.empty()){
		while(!tourney2.empty() && highcardTable2.emptySeat()){
			highcardTable2.addPlayer(tourney2.getPlayer());
		}
		assert(verifyHeap(tourney));
		assert(isHeap(tourney.getArray(), 0));
		vector<Player> loser = highcardTable2.playRound();
		for(auto p: loser){
			if(p.getBudget() > ante){
				tourney2.addPlayer(p);
			}
		}
		assert(verifyHeap(tourney));
		assert(isHeap(tourney.getArray(), 0));
	}
	highcardTable2.printWinner();
	cerr << "\n\t========================PASS========================\n" << endl;

	/*################2 more tests################*/

	return 0;
}
