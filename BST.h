/*
 * BST.h
 *
 *  Created on: Jun 7, 2021
 *      Author: Ahmed Saied
 */

#ifndef BST_H_
#define BST_H_
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstddef>
#include <fstream>
#include <cctype>
#include <cmath>
#include <string>
#include <assert.h>
#include<vector>
using namespace std;

#define ListElemType string
class BST{
public:
    BST();
    ~BST();
    void destructor();
	bool isEmpty();
	BST * left();
	BST * right();
	bool ADD_meeting(const ListElemType &, const int &,const int & );
	void Find( const int &,const int &);
	void MOD(const ListElemType &, const int &,const int & );
	void Delete( const int &,const int &);
	void print();

private:
	bool nullTree;
	int Tree_day;
	ListElemType Tree_title[24];
	BST *leftTree;
	BST *rightTree;
};





#endif /* BST_H_ */

