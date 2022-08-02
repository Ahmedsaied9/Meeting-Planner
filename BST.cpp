/*
 * BST.cpp
 *
 *  Created on: Jun 7, 2021
 *      Author:Ahmed Saied
 */
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstddef>
#include <fstream>
#include <cctype>
#include <cmath>
#include <string>
#include "BST.h"
using namespace std;
int planner = 0;
BST::BST(){
	Tree_day=0;
	 nullTree = true;
     leftTree = NULL ;
     rightTree = NULL;
     for (int i =0; i<24 ; i++)
       Tree_title[i]="";
}


BST :: ~BST(){
	
	this -> destructor();
	
}

void BST :: destructor()
{
	BST* destroy = this ;
	
   if(!nullTree)
	{
	
	if (destroy->leftTree != NULL)
	    destroy->leftTree -> destructor();
    if (destroy->rightTree != NULL)
	   destroy-> rightTree -> destructor();
	delete destroy->leftTree;
	destroy->leftTree = NULL;
	delete destroy->rightTree;
	destroy->rightTree = NULL;
	}
}


bool BST ::isEmpty(){
	return nullTree;

}

BST * BST::left(){

	assert(!isEmpty());
	return leftTree;


}

BST * BST::right(){

	assert(!isEmpty());
	return rightTree;


}

bool BST ::ADD_meeting(const ListElemType &title, const int &day,const int &hour ){
	if(nullTree){
		planner = 1;
		nullTree = false;
		leftTree = new BST;
		if (leftTree == NULL)
			return false;
		////assert(leftTree != NULL);
		//leftTree ->nullTree = true;
		rightTree = new BST;
		if (rightTree == NULL)
			return false;
		//assert(rightTree != NULL);
		//rightTree ->nullTree = true;
		Tree_day = day;
		Tree_title[hour]= title;
		}
	else if(day == Tree_day){
		if(Tree_title[hour] == "")
		  Tree_title[hour]= title;
		else
			cout<<"Conflict"<<" "<<day<<" "<<hour<<'\n';
		}
	else if(day < Tree_day){
		leftTree ->ADD_meeting(title,day,hour);
			}
	else if(day > Tree_day){
			rightTree -> ADD_meeting(title,day,hour);
				}
	return true;
}

void BST :: Delete( const int &day,const int &hour){
	int Q=0;
	if(nullTree){
		cout<<"Empty"<<" "<<day<<" "<<hour<<'\n';
	}
	 else if(day == Tree_day)
	 {
		if(Tree_title[hour] == "")
			cout<<"Empty"<<" "<<day<<" "<<hour<<'\n';
		else
					{
						//Tree_title[hour] = "";
						Q=0;
						for(int i=0;i<=23;i++)
						{
							if(Tree_title[i]== "")
							{
								Q++;
							}

						}
						if( Q==23)
						{
							 BST* toDelete = this;
							 if (toDelete -> leftTree -> nullTree && toDelete -> rightTree -> nullTree)
							    {
							        //Set it as a null tree  to denote that it is empty
							        toDelete->nullTree = true;
							        for(int i=0;i<=23;i++)
							        	Tree_title[i]="";
							        //Delete its nulltree children
							        delete toDelete->leftTree;
							        toDelete->leftTree = NULL;
							        delete toDelete->rightTree;
							        toDelete->rightTree = NULL;

							        return;
							    }

							    //Case 2 : The node to delete only has a left subtree
							    if (! toDelete -> leftTree -> nullTree && toDelete -> rightTree -> nullTree)
							    {
							        //Searching for a node to replace the node to delete while keeping the tree a correct BST. The node to replace must be greater than all the elements in its left
							        //subtree. The node the node that satisfies this condition is the biggest node in the leftsubtree which can be found and the most right node in the left subtree
							        BST* toReplace = toDelete -> leftTree;
							        while(!toReplace -> rightTree -> nullTree) // Stop when there is no longer any more nodes to the right
							        {
							            toReplace = toReplace -> rightTree;//Move to the right
							        }
							        //Swap nodes
							        int temp = toReplace -> Tree_day;
							        string tempTitle[24];
							        for (int k=0;k<=23;k++){
							        	tempTitle[k]= "";
							        }
							        for (int k=0;k<=23;k++){
							        	tempTitle[k]= toReplace->Tree_title[k];
							        }
							        toReplace -> Tree_day = toDelete -> Tree_day;
							        for (int k=0;k<=23;k++){
							        	toReplace->Tree_title[k]= toDelete->Tree_title[k];
							        }
							        toDelete -> Tree_day = temp;
							        for (int k=0;k<=23;k++){
							        	toDelete->Tree_title[k]= tempTitle[k];
							        }
							        //Now we want to delete the toReplace node but it on its own might have its own children in the left subtree so we call remove for it again and not simply delete
							        //This will be called multiple times until a leaf node is reached and at that point a true will be returned and the leaf node will be deleted
							        toReplace->Delete(toReplace->Tree_day,hour);
							        return;
							    }
							    //Case 3 : The node to delete only has a left subtree
							    if ( toDelete -> leftTree -> nullTree && !toDelete -> rightTree -> nullTree)
							    {
							        //Searching for a node to replace the node to delete while keeping the tree a correct BST. The node to replace must be greater than all the elements in its left
							        //subtree. The node the node that satisfies this condition is the biggest node in the leftsubtree which can be found and the most right node in the left subtree
							        BST* toReplace = toDelete -> rightTree;
							        while(!toReplace -> leftTree -> nullTree) // Stop when there is no longer any more nodes to the right
							        {
							            toReplace = toReplace -> leftTree;//Move to the right
							        }
							        //Swap nodes
							        int temp = toReplace -> Tree_day;
							        string tempTitle[24];
							        for (int k=0;k<=23;k++){
							        	tempTitle[k]= "";
							        }
							        for (int k=0;k<=23;k++){
							        	tempTitle[k]= toReplace->Tree_title[k];
							        }
							        toReplace -> Tree_day = toDelete -> Tree_day;
							        for (int k=0;k<=23;k++){
							        	toReplace->Tree_title[k]= toDelete->Tree_title[k];
							        }
							        toDelete -> Tree_day = temp;
							        for (int k=0;k<=23;k++){
							        	toDelete->Tree_title[k]= tempTitle[k];
							        }
							        //Now we want to delete the toReplace node but it on its own might have its own children in the left subtree so we call remove for it again and not simply delete
							        //This will be called multiple times until a leaf node is reached and at that point a true will be returned and the leaf node will be deleted
							        toReplace->Delete(toReplace->Tree_day,hour);
							        return;
							    }
							    //Case 4 : The node to delete only has a left subtree
							    if ( !toDelete -> leftTree -> nullTree && !toDelete -> rightTree -> nullTree)
							    {
							        //Searching for a node to replace the node to delete while keeping the tree a correct BST. The node to replace must be greater than all the elements in its left
							        //subtree. The node the node that satisfies this condition is the biggest node in the leftsubtree which can be found and the most right node in the left subtree
							        BST* toReplace = toDelete -> rightTree;
							        while(!toReplace -> leftTree -> nullTree) // Stop when there is no longer any more nodes to the right
							        {
							            toReplace = toReplace -> leftTree;//Move to the right
							        }
							        //Swap nodes
							        int temp = toReplace -> Tree_day;
							        string tempTitle[24];
							        for (int k=0;k<=23;k++){
							        	tempTitle[k]= "";
							        }
							        for (int k=0;k<=23;k++){
							        	tempTitle[k]= toReplace->Tree_title[k];
							        }
							        toReplace -> Tree_day = toDelete -> Tree_day;
							        for (int k=0;k<=23;k++){
							        	toReplace->Tree_title[k]= toDelete->Tree_title[k];
							        }
							        toDelete -> Tree_day = temp;
							        for (int k=0;k<=23;k++){
							        	toDelete->Tree_title[k]= tempTitle[k];
							        }
							        //Now we want to delete the toReplace node but it on its own might have its own children in the left subtree so we call remove for it again and not simply delete
							        //This will be called multiple times until a leaf node is reached and at that point a true will be returned and the leaf node will be deleted
							        toReplace->Delete(toReplace->Tree_day,hour);
							        return;
							    }
						}

						else
						{
							Tree_title[hour] = "";
						}
						Q=0;

					}
	  }
	 else if(day < Tree_day){
		 leftTree ->Delete(day,hour);
	 }
	 else if(day > Tree_day){
	 		 rightTree ->Delete(day,hour);
	 	 }
}

void BST ::print(){
	if(planner == 0){cout<<"Empty Planner"<<'\n';}
	else if(!nullTree){
		if (rightTree != NULL)
		leftTree->print();

		for(int i=0; i<24 ;i++){
			if(Tree_title[i] != "")
			  cout<< Tree_title[i]<<" "<<Tree_day<<" "<<i<<'\n';
		}
		if (rightTree != NULL)
		rightTree->print();

}
}

//Find function
void BST::Find( const int &day,const int &hour){
	if(nullTree)
		{
		cout<<"Empty "<<day<<" "<<hour<<endl;
		return;//just to terminate the function
		}
	else if (day == Tree_day)
	{
		cout<<Tree_title[hour]<<endl;
		return;
	}
	else if (day <= Tree_day)
		leftTree->Find(day,hour);
	else
		rightTree->Find(day,hour);
}

// Modify function
void BST::MOD(const ListElemType &title, const int &day,const int &hour ){
	if(nullTree)
		{
		cout<<"Empty "<<day<<" "<<hour<<endl;
		return;//just to terminate the function
		}
	else if (day == Tree_day)
	{
		Tree_title[hour]=title;
		return;
	}
	else if (day <= Tree_day)
		leftTree->MOD(title,day,hour);
	else
		rightTree->MOD(title,day,hour);
}






