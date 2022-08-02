/*
 * main.cpp
 *
 *  Created on: Jun 7, 2021
 *      Author: Ahmed Saied
 */
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstddef>
#include <fstream>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;
#include "BST.h"
int main(int argc, char *argv[]){
	if(argc !=2){cout<<"Invalid arguments";return 0 ;}


//BST Planner;
typedef BST * BSTPtr;
BSTPtr Planner(new BST);
string title;
int day;
int hour;
string day_str; string hour_str;
string Command;
string line;
string unwanted;
string temp[10];
string word;
bool day_not_int;
bool hour_not_int;
bool E;
	ifstream Command_file(argv[1]);
	if(Command_file.is_open())
	{
		k:while(getline(Command_file , line))

		{
			day_not_int = false;
			hour_not_int= false;
			E = false;
			istringstream iss(line);
						title.clear();
						iss>>Command;

		if(Command == "ADD"){
			// check either there is valid title or not (for valid title, 'm' must have 2)
			int m =0;
			int TitleBegin = 0; int TitleEnd=0;
			int k = 0;
			while(line[k] != '\0')
			{char cc = line[k];
				if (cc == '"')
					{
					m+=1;
					if(m==1)
						TitleBegin=k;
					if(m==2)
						TitleEnd=k;
					}
				k++;
			}
			if (m == 2)
				{
					for (int h=TitleBegin;h<=TitleEnd;h++)
						title+=line[h];
				}
			else
				{
				cout<<"Invalid title"<<'\n';
				//goto k;
				E = true;
				}
			//line = line -title;
			k=0;
		iss>>temp[k];
		string word=temp[k];
		if(!E){
		while(word[(word.length()-1)] != '"')
				{
					k++;
					iss>>temp[k];
					word=temp[k];

				}
		}
			iss>>day_str>>hour_str>>unwanted;
			for(int j =0; j<int(day_str.length()); j++)
				if(day_str[j]=='.' ){day_not_int = true;}
			for(int j =0; j<int(hour_str.length()); j++)
				if(hour_str[j]=='.'){hour_not_int = true;}
			stringstream num(day_str);
			num >> day;
			stringstream num1(hour_str);
						num1 >> hour;
			//c1 = title[0]; c2 = title[title.length()-1];
	        if(unwanted != ""){cout<<"Invalid arguments"<<'\n';unwanted.clear();goto k;}
	       // if(c1!='"' && c2!='"'){cout<<"Invalid title"<<'\n'; goto k;}
	        if(day<1 || day>365 || day_not_int){cout<<"Invalid day"<<'\n';unwanted.clear();E = true;}
	        if(hour <0 || hour >23 || hour_not_int){cout<<"Invalid hour"<<'\n';unwanted.clear();E = true;}

         if(!E)
	       Planner ->ADD_meeting(title,day,hour);

		}

		else if(Command == "Find"){
			iss>>day_str>>hour_str>>unwanted;
			for(int j =0; j<int(day_str.length()); j++)
				if(day_str[j]=='.'){day_not_int = true;}
			for(int j =0; j<int(hour_str.length()); j++)
				if(hour_str[j]=='.'){hour_not_int = true;}
			stringstream num(day_str);
						num >> day;
						stringstream num1(hour_str);
									num1 >> hour;
			        if(unwanted != ""){cout<<"Invalid arguments"<<'\n';unwanted.clear();goto k;}
			        if(day<1 || day>365|| day_not_int){cout<<"Invalid day"<<'\n';unwanted.clear();E = true;}
			        if(hour <0 || hour >23|| hour_not_int){cout<<"Invalid hour"<<'\n';unwanted.clear();E = true;}
                   if(!E)
			        Planner->Find(day,hour);


				}


		else if(Command == "MOD"){
			int m =0;
						int TitleBegin = 0; int TitleEnd=0;
						int k = 0;
						while(line[k] != '\0')
						{char cc = line[k];
							if (cc == '"')
								{
								m+=1;
								if(m==1)
									TitleBegin=k;
								if(m==2)
									TitleEnd=k;
								}
							k++;
						}
						if (m == 2)
							{
								for (int h=TitleBegin;h<=TitleEnd;h++)
									title+=line[h];
							}
						else
							{
							cout<<"Invalid title"<<'\n';
							//goto k;
							E = true;
							}
						//line = line -title;
						k=0;
					iss>>temp[k];
					string word=temp[k];
					while(word[(word.length()-1)] != '"')
							{
								k++;
								iss>>temp[k];
								word=temp[k];

							}
						iss>>day_str>>hour_str>>unwanted;
						for(int j =0; j<int(day_str.length()); j++)
										if(day_str[j]=='.'){day_not_int = true;}
									for(int j =0; j<int(hour_str.length()); j++)
										if(hour_str[j]=='.'){hour_not_int = true;}
						stringstream num(day_str);
						num >> day;
						stringstream num1(hour_str);
									num1 >> hour;
			if(unwanted != ""){cout<<"Invalid arguments"<<'\n';unwanted.clear();goto k;}
			if(day<1 || day>365 || day_not_int){cout<<"Invalid day"<<'\n';unwanted.clear();E = true;}
		    if(hour <0 || hour >23 || hour_not_int){cout<<"Invalid hour"<<'\n';unwanted.clear();E = true;}
			if(!E)
		      Planner->MOD(title,day,hour);

				}


		else if(Command == "DEL"){
						        iss>>day_str>>hour_str>>unwanted;
						        for(int j =0; j<int(day_str.length()); j++)
						        	if(day_str[j]=='.'){day_not_int = true;}
						        for(int j =0; j<int(hour_str.length()); j++)
						           if(hour_str[j]=='.'){hour_not_int = true;}
						        stringstream num1(day_str);
						        			num1 >> day;
						        			stringstream num(hour_str);
						        						num >> hour;
						        if(unwanted != ""){cout<<"Invalid arguments"<<'\n';unwanted.clear();goto k;}
						        if(day<1 || day>365 || day_not_int){cout<<"Invalid day"<<'\n';unwanted.clear();E = true;}
						        if(hour <0 || hour >23 || hour_not_int){cout<<"Invalid hour"<<'\n';unwanted.clear();E = true;}
						        if(!E)
						          Planner->Delete(day,hour);

				}
		else if(Command == "Print"){
			iss>>unwanted;
			        if(unwanted != ""){cout<<"Invalid arguments"<<'\n';unwanted.clear();goto k;}
                      Planner->print();
				}
		else
			cout<<"Invalid command"<<'\n';



		}
	}
	else
			{
				cout<<"File not Found";
				Planner ->~BST();
               // delete Planner;
			    return 0;
			}






	Planner ->~BST();
	//delete Planner;


return 0; }

