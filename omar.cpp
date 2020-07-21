#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;

class address__book{
	string FirstNamE;
	string LastNamE;
    string addresS;
	string EMAIL;
	string PhoneNumber;
	public:
		//constructor
		addressbook(string a="",string b="",string c="",string d="",string e=""){
			FirstNamE=a;
			LastNamE=b;
			addresS=c;
			EMAIL=d;
			PhoneNumber=e;
		}
		
		//getters
		string G_fname()const{
			return FirstNamE;
			
		}
	    string G_lname()const{
	    	
	    	return LastNamE;
		}
		string G_address()const{
			return addresS;
		}
		string G_email()const{
			return EMAIL;
		}
		string G_number()const{
			return PhoneNumber;
		}
		
		//setters
		void S_fname(string X){
			FirstNamE=X;
			
		}
		void S_lname(string X){
			LastNamE=X;
			
		}
		void S_address(string X){
			addresS=X;
			
		}
		void S_email(string X){
			EMAIL=X;
			
		}
		void S_number(string X){
			PhoneNumber=X;
			
		}
		
		bool operator==(address__book T){
			return (this->FirstNamE==T.G_fname() && LastNamE==T.G_lname() && addresS==T.G_address() && EMAIL==T.G_email() && PhoneNumber==T.G_number());
		}
		friend ostream & operator<< (ostream &out , address__book & b){
			out<<b.G_fname()<<" "<<b.G_lname()<<" "<<b.G_address()<<" "<<b.G_email()<<" "<<b.G_number()<<endl;
			return out;
		}
		friend istream & operator>>(istream & in ,address__book & b){
			
			in>>b.FirstNamE>>b.LastNamE>>b.addresS>>b.EMAIL>>b.PhoneNumber;
		}
		friend fstream &operator <<(fstream&file,address__book&b){
		file<<b.G_fname()<<"|"<<b.G_lname()<<"|"<<b.G_address()<<"|"<<b.G_email()<<"|"<<b.G_number()<<endl;
		return file;
		}
};
fstream MY_File;
address__book CONTACTS;
address__book t1 , t2;
address__book data[100];
address__book s_data[100];
bool save = false ; 
	int XX ; 
	int Counter=0;
	string AA;
	void convert(const string record);
	void FilE__ArrAy()
	{
    	MY_File.open("data.txt",ios::in|ios::app|ios::out);
    	if(!MY_File){
		cout<<"can't open the file in the current mode5";
		exit(1);
	}
		
	while(true){
		MY_File>> AA;
			if(MY_File.eof()){
			break;
		}
		
		convert(AA);
		data[Counter] = CONTACTS;
         	Counter++;
	}
	MY_File.close();
	}
void save__data()
{
	MY_File.open("data.txt",ios::out|ios::trunc);
	if(!MY_File){
		cout<<"can't open the file in the current mode5";
		exit(1);
		
	}
	
	for(int i = 0 ; i < Counter ; i++)
	{
	  MY_File<<data[i];
	  }	
	  MY_File.close() ;
}
void SwapPing(address__book *x, address__book *y)  
{  
    address__book temp = *x;  
    *x = *y;  
    *y = temp;  
} 
 void bubble_s( )  
{  

for(int i = 0 ; i < Counter ; i ++)
   {
   s_data[i]=data[i];
   }
   
    int i, j;  
    for (i = 0; i < Counter-1; i++)      
    for (j = 0; j < Counter-i-1; j++)  
        if (s_data[j].G_fname() > s_data[j+1].G_fname())  
            SwapPing(&s_data[j], &s_data[j+1]);  
}  
void B__S (address__book R[], int L_eft, int R_ight, string keyy) 
{ 

    if (R_ight >= L_eft) { 
        int mid = L_eft + (R_ight - L_eft) / 2; 
        if ( s_data[mid].G_fname() == keyy)
		{  
		  
		   cout << "\n contact not found \n" ;
           cout<<R[mid] ;
           return;
		} 
        if (R[mid].G_fname() > keyy) 
        	return B__S(R, L_eft, mid - 1, keyy);
        if(R[mid].G_fname() < keyy )
        	 return B__S(R, mid + 1, R_ight, keyy); 
    } 
    return ; 
} 
void add_COntacT(){

	cout<<"entre new contact info \n";
	
	cin>>data[Counter];
	cout << data [Counter];
	Counter++;
}
void convert(const string record){
	stringstream strs(record);
	
	string s_firstname,s_lastname,s_address,s_email,s_number;
	getline(strs,s_firstname,'|');
	getline(strs,s_lastname,'|');
	getline(strs,s_address,'|');
	getline(strs,s_email,'|');
	getline(strs,s_number,'\n');
	
	CONTACTS.S_fname(s_firstname);
	CONTACTS.S_lname(s_lastname);
	CONTACTS.S_address(s_address);
	CONTACTS.S_email(s_email);
	CONTACTS.S_number(s_number);
	
}
void D_all_file(){
	for(int y = 0 ; y < Counter ; y++)
	{
		cout<<data[y];
	}
}
void Search_Contact(){
	string name;
	cout<<"insert contact name \n";
	cin>>name;
 for (int i = 0 ; i < Counter ; i ++ )
 {
 	if (data[i].G_fname()==name)
 	{
 		cout<<"contact is found .\n"<<data[i]<<endl;
 		return ;
	 }
 }
	cout<<"contact not found \n";	
	return ; 
}
void MODIFY__CONTACT(){

	string uname;
	cout<<"insert contact name ";
	cin>>uname;
	int i=0;
	for(;i<Counter;i++){
		
		if(data[i].G_fname()==uname){
			XX = i ; 
			t1 = data[i] ;
			cout<<"\n old  info :";
			cout<<data[i];
			cout<<"\n insert new info ";
			cin>>data[i];
			return ;
	   }
	}
      cout<<"not found !";
	}

void Del_C(){
	string D_name;
	cout<<"insert contact name ";
	cin>>D_name;
	int i=0;
	for(;i<Counter;i++){
		
		if(data[i].G_fname()==D_name){
			cout<<"\n  contact will  delete:";
			cout<<data[i];
				for(int j=i;j<Counter;j++){
		           data[j]=data[j+1];}
		           Counter--;
			return ;
	   }
	}
	cout<<"\ncontact not found";
	return; 
} 
int main(){
	FilE__ArrAy();
	int op = 1;
	int choice;
	while(true){
		cout<<"\n 0: exit ";
		cout<<"\n 1: insert new contact ";
		cout<<"\n 2: show all contacts ";
		cout<<"\n 3: modify contact ";
		cout<<"\n 4: search for contact liner & binary";
		cout<<"\n 5: remove a contact ";
		cout<<"\n 6: save data ";
		cout<<"\n 7:  undo last updat ";
        cout<<"\n 8:  redo last undo ";
cout<<"entre your choice : ";
cin>>choice;
switch(choice){
	case 0:
		save__data();
		exit(0);
		break;
	case 1:
	add_COntacT();
		op++;
	    break;
	case 2:
		D_all_file();
		op++;
		break;
	case 3:
		MODIFY__CONTACT();
		op++;
		break;
	case 4:
		int v ;
		cout<<"search press 1 binary  .... press 2 liner";
		cin>>v;
		 switch (v)
		 {
		 	case 1 : {
			 bubble_s( );
		 	string z ; 
		 	cout << "enter key";
		 	cin>> z;
			 bubble_s( );B__S(s_data , 0 ,Counter, z );
			 }
			 break;
			case 2 : Search_Contact();	break;
		 }
		op++;
		break;
	case 5:
		Del_C();
		op++;
		break;	
	case 6:
	save__data();
	break;
	case 7: 
	   t2 = data[XX];
	   data[XX] = t1 ;
	   cout << data[XX];	
	   break ;
	case 8: 
	   data[XX] = t1 ;
	   cout<<data[XX];
	default :
	cout<<"invalid input ...\n";
	    break;	
	    if(op == 5 )
	    {
	    	save__data();
		}
}
}	
	return 0;
}
