#ifndef bst_h
#define bst_h
#include<iostream>
#include "bnode.h"
using namespace std;

class bst
{
    private:
        bnode<int>* root;
        int key;
        int count;
        void RecAdd(int entry,bnode<int> *current);
        
        void LevelOrder(int level,bnode<int>*current);
        void spiralevel(int level,bnode<int>* current);

        int getheight(bnode<int>*current);
        string output_storage;
        void deleteAll(bnode<int>*current);//for distructor

        bnode<int>* RecRemove(bnode<int>*current,int item);
        bnode<int>* Removenode(bnode<int>*current);

        void inordertr(bnode<int>*current);//test 
        

        int RecSearch(bnode<int>* current,int key);
        
        bnode<int>* Nodecopy;
        bnode<int>* InorderSccu(int item,bnode<int>* current); //find successor 1/3
        bnode<int>* minValuenode(bnode<int>*current);//find successor 2/3
    public:
        bst();
        int InorderSuccessor(int item);//find successor 3/3
        void remove(int item);
        void clear();

        string Level_trv();
        string spiral_trv();

        bool Search(int item);

        string leftsideview();
        string rightsideview();

        void addItem(int entry);
        void deleteItem(int entry);

        string kthSmall(int entry);
        ~bst();
};
#endif
