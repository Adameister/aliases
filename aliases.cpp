/*
* Name: Adam Hudson
* Date: Oct 20, 2016
* Bash_aliases Editor
* Description: 	An editor to read and write alises
*				from the aliases file
*/

// this file has been modified 

//	ofstream:	Stream class to write on files
//	ifstream:	Stream class to read from files
//	fstream:	Stream class to both read and write to/from files

#include <iostream>
#include <fstream>
#include <string>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

int write(){
	string line;
	string uInput = "";
	fstream file;
	
	file.open ("/home/adam/.bash_aliases", ios_base::app);
	cout << "Please enter the new alises\n";
	cout << "alisesWrite>";
	getline( cin, uInput );
	file.close();

	return EXIT_SUCCESS;
}

int read(){
	string line;
	fstream file;

	file.open ("/home/adam/.bash_aliases");
	while(!file.eof()){	// go while not end
		getline(file, line);	// saves the line in line
		cout << line << '\n';
	}
	file.close();

	return EXIT_SUCCESS;
}

int run_cmd(string cmd){

	if( cmd == "help" ){
		cout << "List of commands:" << "\n\n";
		cout << "\thelp:\t\tdisplays this list\n";
		cout << "\tread:\t\tread all of the aliases from the bash_aliases file\n";
		cout << "\twrite:\t\tprompts user to enter new alises\n";
	}
	else if( cmd == "read" ){
		read();
	}
	else if( cmd == "write" ){
		write();
	}
	else{
		cout << cmd << ": Command not recognized\n" << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int main(){
	string uInput = "";

	cout << "Welcome to Adam's bash_aliases editor!" << '\n';
	cout << "Please enter an option\n";

	while( 1 ){
		cout << "alisesEdit>";
		getline( cin, uInput );
	
		// code found on SO for boost tokenizing
		char_separator<char> sep(" ");
		tokenizer< char_separator<char> > tokens( uInput, sep );
		BOOST_FOREACH( const string& t, tokens ){
			if( t == "exit" || t == "quit" ){
				cout << "\nExiting alisesEdit...\n";
				return EXIT_SUCCESS;
			}
			run_cmd( t );
		}
	}


	return EXIT_SUCCESS;

}