//					>>>REGISTRATION AND LOGIN FORM<<<
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Creating class of User
class User{
	private:
		string username, password;
	public:
		// contructer for setting username and password
		User(string name, string pass){
			username = name;
			password = pass;
		}
	
	// creating getmethods to return username and password for login 
	string getUsername(){
		return username;
	}
	string getPassword(){
		return password;
	}
};

// Creating class of UserManager
class UserManager{
	private:
		vector<User> users;		// creating objects of vector
	public:
		void RegisterUser(){
			string username, password;
			cout<<"Enter Username: "<<endl;
			cin>>username;
			cout<<"Enter Password: "<<endl;
			cin>>password;
			
			User newUser(username, password);
			users.push_back(newUser);
			
			cout<<"\t\t User Registerd Successfully ..."<<endl;
		}
			
		bool LoginUser(string name, string pass){
	    	for(int i=0; i<users.size(); i++){
	        	if(users[i].getUsername() == name && users[i].getPassword() == pass){
	            cout<<"\n\t\t User Login Successfully"<<endl;
	            return true;
	        }
	    }
	    // If the loop finishes and no match is found, return false
	    	cout<<"\n\t\t Invalid User"<<endl;
	    	return false;
		}
		
		void showUser(){
			cout<<"\t\t-----USERS LIST-----"<<endl;
			for(int i=0; i<users.size(); i++){
				cout<<"\t\t"<<users[i].getUsername()<<endl;
			}
		}
		
		
		
		void searchUser(string name){
			for(int i=0; i<users.size(); i++){
				if(users[i].getUsername() == name){
					cout<<"\t\t User found"<<endl;
				}
			}
		}
		
		void deleteUser(string username){
			for(int i=0; i<users.size(); i++){
				if(users[i].getUsername() == username){
					users.erase(users.begin() + i);
					cout<<"\t\t User remove Successfully ..."<<endl;
				}
			}
		}
};

int main(){
	
	// creating object of UserManager class
	UserManager usermanage;
	
	int opt;
	char choice;
	
	do{
		system("cls");
		// creating menu
		cout<<"\n\n\t\t 1. Register User"<<endl;
		cout<<"\t\t 2. Login"<<endl;
		cout<<"\t\t 3. Show User List"<<endl;
		cout<<"\t\t 4. Search User"<<endl;
		cout<<"\t\t 5. Delete User"<<endl;
		cout<<"\t\t 6. Exit"<<endl;
		
		cout<<"\n\t\t Enter your choice: "<<endl;
		cin>>opt;
		switch(opt){
			case 1:{
				// calling registerUser method
				usermanage.RegisterUser();
				break;
			}
				
			case 2:{
					string username, password;
				cout<<"Enter Username:"<<endl;
				cin>>username;
				cout<<"Enter Password:"<<endl;
				cin>>password;
				
				// calling LoginUser method
				usermanage.LoginUser(username,password);
				break;
			}
			
			case 3:{
				usermanage.showUser();
				break;
			}
			
			case 4:{
				string username;
				cout<<"\t\t Enter Username: "<<endl;
				cin>>username;
				usermanage.searchUser(username);
				break;
			}
			case 5:{
				string username;
				cout<<"\t\t Enter Username: "<<endl;
				cin>>username;
				usermanage.deleteUser(username);
				break;
			}
		}
		cout<<"Do You Want to Continue ...?[(Yes/No] : "<<endl;
		cin>>choice;
	}while(choice == 'y' || choice == 'Y');
	
	
}
