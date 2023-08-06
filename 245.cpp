// UVa-245: Uncompress.cpp
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class word                  // class word
{
	public:
		string s;           // s: an existed word
		word* next;         // next: the pointer to the next word
		
		word(string init)   // constructor
		{
			s=init;
			next=NULL;
		}
};

int is_number(char ch)      // whether the input is a number
{
	if(ch>='0' && ch<='9') return 1;
	else return 0;
}

int is_alphabet(char ch)    // whether the input is an alphabet (word)
{
	if((ch>='a'&& ch<='z') || (ch>='A'&& ch<='Z')) return 1;
	else return 0;
}

int main(void)
{
	char ch;
	word *head;             // head: the start of a list storing existed words
	
	ch=getchar();           // use getchar() so that a blanck can be read
	while(ch!='0')          // until the end 
	{
		if(is_number(ch))   // deal with a number
		{
			int num=0;
			while(is_number(ch))       // convert to a decimal number of the list
			{
				num=num*10+(ch-'0');
				ch=getchar();           
			}
			
			int i;                     // get the word from the list
			word *current=head, *pre;
			for(i=1; i<num; i++)
			{
				pre=current;
				current=current->next;
				
			}
			cout << current->s;
			
			if(num!=1)                 // move the word to the front of the list
			{
				pre->next=current->next;
				current->next=head;
				head=current;
			}
		}
		
		else if(is_alphabet(ch))       // deal with an alphabet (word)
		{
			string tmp;
			while(is_alphabet(ch))     // get the full word
			{
				tmp+=ch;
				ch=getchar();             
			}
			
			cout << tmp;               // print out the word
			
			word *n=new word(tmp);     // store the word to the list
			n->next=head;
			head=n;
		}
		
		else                           // deal with other symbols
		{
			cout << ch;				   // print out the symbol directly
			ch=getchar();
		}
	}
	
	/*
	// return dynamic allocation
	// this part will cause runtime error
	word *current=head, *tmp;          
	while(current!=NULL)
	{
		tmp=current;
		current=current->next;
		delete tmp;
	}
	*/
	
	return 0;
}
