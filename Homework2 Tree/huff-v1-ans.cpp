#include <iostream>  
#include <vector>  
#include <string>  
using namespace std;  
  
struct Node {  
    string s;  
    int weight;  
    Node( string code, int n ) { s = code; weight = n; }  
};  
  
vector<Node> v;  
vector<Node>::iterator it;  
  
void encode( string s, int n ) {  
    for ( it = v.begin(); it != v.end(); it++ ) {  
        if ( n >= it->weight )  
            break;  
    }  
    v.insert( it, Node( s, n ) );  
}  
  
int main()  
{  
    int n;  
    int i;  
    int keep;  
    char c;  
    string s, left, right;  
    int freq[ 26 ] = { };  
    string code[ 26 ] = { };  
  
    cin >> n;  
    while ( n-- ) {  
        cin >> c;  
        freq[ c - 'A' ]++;  
    }  
  
    for ( i = 0; i < 26; i++ ) {  
        if ( freq[ i ] != 0 ) {  
            s = 'A' + i;  
            encode( s, freq[ i ] );  
        }  
    }  
  
    while ( v.size() != 1 ) {  
        left = v.back().s;  
        for ( i = 0; i < left.size(); i++ )  
            code[ left[ i ] - 'A' ] = '0' + code[ left[ i ] - 'A' ];  
        keep = v.back().weight;  
        v.pop_back();  
  
        right = v.back().s;  
        for ( i = 0; i < right.size(); i++ )  
            code[ right[ i ] - 'A' ] = '1' + code[ right[ i ] - 'A' ];  
        keep += v.back().weight;  
        v.pop_back();  
  
        encode( left + right, keep );  
    }  
  
    while ( true ) {  
        keep = 0;  
        for ( i = 1; i < 26; i++ ) {  
            if ( freq[ i ] > freq[ keep ] )  
                keep = i;  
        }  
  
        if ( freq[ keep ] != 0 ) {  
            cout << (char)('A' + keep) << " " << freq[ keep ] << " " << code[ keep ] << endl;  
            freq[ keep ] = 0;  
        }  
        else  
            break;  
    }  
  
    return 0;  
  
}                    