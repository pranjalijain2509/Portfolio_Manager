#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;

void mainpage(){
	cout<<"\n\t\tCV READER ";
	cout<<"\n\n\t\'U\'pload";
	cout<<"\n\n\t'S'ample Resume";
	cout<<"\n\n\t'H'elp";
	cout<<"\n\n\t'A'bout Us ";
}
char designation(){
	system("cls");
	cout<<"\n\t\tCv READER ";
	cout<<"\n\n\t'S'oftware Developer ";
	cout<<"\n\n\tSoftware 'E'ngineer ";
	cout<<"\n\n\t'W'eb Developer";
	return getch();
}
int upload(){
	char a[200],s;
	int i=0,k,j;
	
	system("cls");
	cout<<"\n\t\tCV Reader";
	cout<<"\n\nEnter the file name (with Extention) : ";
	cin>>a;
	s=designation();
	ifstream fin(a,ios::in);
	if(!fin){
		cout<<"file not found !";
		return 1;
	}
	fin.seekg(0);
	char st[180][20];
	
	while(fin){
		fin.getline(st[i],20,' ');
		i++;
	}
	for(j=0;j<i;j++){
		cout<<st[j];
	}
	if(s=='S'||s=='s'){
		char ATS[5][20]={"Confident", "Analytics","Speaker", "Presenter", "Competitive" };
		int cats=0,clang=0,cskills=0;
		char lang[5][20]={"Java","English","Python","C++","Ruby"};
		char skills[5][20]={"Coder","Presenter","Competitive", "Leader", "Strategic"  };
		fin.seekg(0);
		for(j=0;j<5;j++){
		   for(k=0;k<i;k++){
		   	if(strcmpi(ATS[j],st[k])==0){
		   		cats++;
		   		strcpy(ATS[j],"NULL");
			   }
			if(strcmpi(lang[j],st[k])==0){
		   		clang++;
		   		strcpy(lang[j],"NULL");
			   }
			if(strcmpi(skills[j],st[k])==0){
		   		cskills++;
		   		strcpy(skills[j],"NULL");
			   }
		   }	
		}
		system("cls");
		cout<<"\n\t\tCV READER";
		cout<<"\n\n\tATS Finding : "<<(cats/5.0)*100<<"%";
		cout<<"\n\n\tLanguage Required :"<<(clang/5.0)*100<<"%";
		cout<<"\n\n\tSkills Match : "<<(cskills/5.0)*100<<"%";
		cout<<"\n\n Overall chances to get selected :  "<<((cats+clang+cskills)/15.0)*100<<"%";
		cout<<"\n---------------------------------------------------------------";
		cout<<"\n\n\t\tSUGGESTIONS : ";
		cout<<"\n\nTry to add these in you CV : ";
		for(j=0;j<5;j++){
			if(strcmpi(ATS[j],"NULL")==0){
				continue;
			}
			cout<<ATS[j]<<" , ";
		}
		cout<<"\n\nLearn These Languages : ";
		for(j=0;j<5;j++){
			if(strcmpi(lang[j],"NULL")==0){
				continue;
			}
			cout<<lang[j]<<" , ";
		}
		cout<<"\n\nGet these Skills : ";
		for(j=0;j<5;j++){
			if(strcmpi(skills[j],"NULL")==0){
				continue;
			}
			cout<<skills[j]<<" , ";
		}
		
	}
	else{
		system("cls");
		cout<<"\n\n\t\t Work is in the progress ! Sorry for inconvinence";
	}
	
	
	
	
fin.close();	
}
main(){
	char ch;
	mainpage();
	ch=getch();
	if(ch=='U'||ch=='u' ){
		upload();
	}
	else{
		system("cls");
		cout<<"\n\n\t\t Work is in the progress ! Sorry for inconvinence";
	}
	
	getch();
	
}
