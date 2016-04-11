#include <iostream>
#include <map>
using namespace std;

int main()
{
	map< string, pair<float,int> > motorways;

	motorways.emplace( "M1", make_pair<float,int>(193.5, 1959) );
	//                 [...]
	motorways.emplace( "M898", make_pair<float,int>( 0.5, 1985 ) );

	cout << "The " << "M1" << " is " << 
		motorways.find("M1")->second.first << " miles long" << endl;

	cout << "The " << "M898" << " opened in " << 
		motorways.find("M898")->second.second << endl;

	return 0;
}