#include <iostream>
#include <string>
#include <cassert>


using namespace std;

/**
Return the index of the smallest item found in the array or -1 if n <= 0.
For example, for the array people[ 5 ] shown above,
locateMinimum( people, 5 )should return the value 3,
corresponding to the index of "daenerys".
If there are multiple duplicate minimum values,
please return the smallest index that has this smallest item.
*/
int locateMinimum( const string array[ ],int n) {
  if ( n < 0 ) return -1;

  int min = 0;

  for ( int i =1; i<=sizeof(array); i++){
    if ( array[i].compare(array[min]) < 0 ) {
      min = i;
    }
}

  return min;
}

/**
Return the largest index that holds the target value in the array or -1
if it is not found at all or n <= 0.  For example,
string data[ 4 ] = { "howard", "ucla", "howard", "ucla" };
findLastOccurrence( data, 4, "howard" ) should return the value 2
findLastOccurrence( data, 4, "cs 31" )   should return -1.
*/
int findLastOccurrence( const string array[ ], int n, string target ) {
  if ( n < 0 ) return -1;

  for ( int i = n-1; i >= 0; i--) {
    if ( array[i].compare(target)==0 ){
      return i;
    }
  }

  return -1;
}

/**
Flips the items found in the array so that the first item holds what was originally found in the last item,
the last item holds what was originally found in the first item, and so on throughout the array.
The function should keep track of all the flips it performs and return that count.
For example, for the array people[ 5 ] shown above,
flipAround( people, 5 ) should adjust the array so that it now holds
{ "tyrion", "daenerys", "margaery", "jon", "samwell" };
and should return 2 (because it performed the flip of samwell and tyrion and the flip of jon and daenerys).
*/
int flipAround( string array[ ],int  n ){
  int start = 0;
  int end = n-1;
  int count = 0;
  while ( start < end){
    swap (array[start++], array[end--]);
    count++;
  }

  return count;
}

/**
If every value in the array is unique and unduplicated, return true otherwise false or if n < 0 return false.
For example, for the array  people[ 5 ]  shown above,  hasNoDuplicates( people, 5 )  should return true.
For example, for the array  people[ 5 ]  shown above,  hasNoDuplicates( people, 0 ) should return true
because the empty array indeed has no duplicates either.
*/
bool hasNoDuplicates( const string array[ ], int n ){

  for ( int i = 0;i<n; i++){
    for ( int j = 0;j<n; j++){
      if ( i!= j && array[i].compare(array[j]) == 0){
        return false;
      }
    }
  }

  return true;
}

void unionWithNoDuplicates( const string array1[ ], int n1, const string array2[ ], int n2, string resultingString[ ],int& resultingSize ){
  int index = 0;
  for ( int i = 0;index<resultingSize, i<n1;i++){
    int find = 0;
    for ( int j = 0; j <index;j++){
      if (array1[i].compare(resultingString[j]) == 0){
        find = 1;
      }
    }
    if ( find == 0){
      resultingString[index++] = array1[i];
    }
  }

  for ( int i = 0;index<resultingSize, i<n1;i++){
    int find = 0;
    for ( int j = 0; j <index;j++){
      if (array2[i].compare(resultingString[j]) == 0){
        find = 1;
      }
    }
    if ( find == 0){
      resultingString[index++] = array2[i];
    }
  }

  resultingSize = index;
}

/**
Adjust the items found in the array, shifting each value to the right by amount parameter,
filling the resulting first amount elements of the array with the placeholder parameter
and returning the number of original array items still remaining in the array after all the shifting has been performed.
For example,  for the array people[ 5 ]  shown above,  shiftRight( people, 5, 3, "foo" )
should return 2 and adjust the array to have the value { "foo", "foo", "foo", "samwell", "jon" };
If the amount parameter is less than zero or exceeds n, return -1.
*/
int shiftRight( string array[ ], int n, int amount, string   placeholderToFillEmpties ){
  if ( amount > n || amount < 0) return -1;
  int count = 0;

  for ( int i = n-1-amount; i>= 0; i--){
    swap (array[i], array[i+amount]);
    count++;
  }

  for ( int i = 0; i<amount;i++){
    array[i] = placeholderToFillEmpties;
  }

  return count;
}

/**
If every value in the array is larger than the one that precedes it, return true
otherwise  false or if n < 0 return false .
For example, for the array  people[ 5 ] shown above, isInIncreasingOrder( people, 5 )  should return false.
When passed an array of size 0 or 1, isInIncreasingOrder( ... ) will return true,
since the function will not find a pair of values that fail to meet the ordering criteria.
*/
bool isInIncreasingOrder( const string array[ ], int  n ) {
  if ( n <= 1) {
    return true;
  }

  for ( int i = 1; i<n; i++){
    if ( array[i].compare(array[i-1]) <= 0){
      return false;
    }
  }

  return true;
}

int main() {
  string folks[8] = {"samwell", "jon", "margaery", "daenerys","tyrion", "sansa", "howard", "cersei"};
  string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
  string data[ 4 ] = { "howard", "ucla", "howard", "ucla" };
  string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
  string b[6] = { "delta", "gamma", "beta", "alpha", "beta", "alpha" };
  string h[7] = { "samwell", "jon", "margaery", "daenerys", "", "tyrion", "margaery" };


  assert(locateMinimum( people, 5 ) == 3);
  assert(locateMinimum( a, 3 ) == 0);

  assert(findLastOccurrence( data, 4, "howard" ) == 2);
  assert(findLastOccurrence( data, 4, "cs 31" ) == -1);

  assert(flipAround(b, 4) == 2);
  assert(flipAround(b, 3 ) == 1);

  assert(hasNoDuplicates(a, 6) == false);
  assert(hasNoDuplicates(a, 3) == true);

  string output[6] = { " ", " ", " ", " ", " ", " "  };
  int outputSize = 6;
  unionWithNoDuplicates(a, 6, b, 2, output, outputSize );
  assert( outputSize == 4 );
  assert( output[0] == "alpha" );

  int answer = shiftRight(h, 6, 1, "foobar" );
  assert( answer == 5 );
  assert( h[0] == "foobar" );

  assert(isInIncreasingOrder(a, 3) == true);
  assert(isInIncreasingOrder(a, 6) == false);

  return 0;
}
