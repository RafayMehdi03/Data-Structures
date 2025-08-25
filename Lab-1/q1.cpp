#include <iostream>
using namespace std ;

class BankAccount{
	int balance ;
  public:
  	BankAccount(){
  		balance = 0 ;
  		cout << "Balance of account 1 : " << balance << endl ;
	  }
	BankAccount(int bal){
		balance = bal ;
		cout << "Balance of account 2 : " << balance << endl ;
	}
	BankAccount(const BankAccount &acc){
		balance = acc.balance - 200 ;
		cout << "Balance of account 3 : " << balance << endl ;
		cout << "Balance of account 2 : " << acc.balance << endl ;
	}
  	
};
int main(){
	BankAccount account1 ;
	BankAccount account2(1000) ;
	BankAccount account3(account2) ;
}
