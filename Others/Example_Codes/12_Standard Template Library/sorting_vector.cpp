#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename verituru>
bool azalan_sirada( verituru a, verituru b ) {
     return a > b;
   }

int main()
{
/*   vector<int> v;
   v.push_back( 20 );
   v.push_back( 10 );
   v.push_back( 40 );
   v.push_back( 30 );
*/
   vector<string> v;
   v.push_back("Bulent");
   v.push_back("Ahmet");
   v.push_back("Kemal");
 
   cout << "Before sorting: ";
   for( unsigned int i = 0; i < v.size(); i++ ) {
     cout << v[i] << " ";
   }
   cout << endl;
 
//   sort( v.begin(), v.end() );
//   sort( v.begin(), v.end() , azalan_sirada<int>);
   sort( v.begin(), v.end() , azalan_sirada<string>);
 
   cout << "After sorting: ";
   for( unsigned int i = 0; i < v.size(); i++ ) {
     cout << v[i] << " ";
   }
   cout << endl;

    return 0;
}


