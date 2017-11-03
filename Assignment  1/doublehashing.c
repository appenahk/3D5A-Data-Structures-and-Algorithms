//Kieta Appenah 21 October 2016

#include <stdio.h> // printf() etc.
#include <string.h> // strcpy(), strlen() etc.

//
// i #define array lengths so i only have to change them in one place
#define NUM_TEST_KEYS 17
#define MAX_KEY_LENGTH 16
#define HASH_TABLE_SIZE_M 17

//
// -- the hash table itself --
char hash_table[HASH_TABLE_SIZE_M][MAX_KEY_LENGTH];

//
// -- example hash function skeleton --
// if it finds the key in the table it should return that index
// otherwise return the appropriate empty index or -1 if table is full
int hash_function( const char *key, int table_size ) {
	int index = strlen(key)%(table_size);

	//
	// write your hash function here
	//

	//
	// consider counting the number of probes it takes to store
	// your key and printing that out

	return index;
}
int another_hash_function( const char *key, int table_size ) {

	int index = 0;
	index = index + key[3]*strlen(key); 
	return index%table_size;
}
float loadcalc(float keys, float tablesize)
{
	float load = keys/tablesize;
	return load;
}
int main() {

	//
	// example: array of test strings to use as keys
	char test_strings[NUM_TEST_KEYS][MAX_KEY_LENGTH] = {
		"prince adam", "orko", "cringer", "teela", "aleet", "princess adora", "orko"
	};

	//
	// example: store each key in the table and print the index for each test key
	printf(
		"             key      table index\n-----------------------------------\n" );
	for ( int i = 0; i < NUM_TEST_KEYS; i++ ) {
        int index = 0;
        int probe = 0;
	index = hash_function( test_strings[i], HASH_TABLE_SIZE_M );
        
        while(hash_table[index][0] != 0)
	{
		index = index + another_hash_function( test_strings[i], HASH_TABLE_SIZE_M );
		index = index%HASH_TABLE_SIZE_M;
		probe++;
        }
         
	if(hash_table[index][0] == 0)
	{
		probe++;
		strcpy(hash_table[index], test_strings[i]);
        }
         
		// i would check for errors and store the keys in the table here
		//

		// the %16s means print a string (%s) but pad it to 16 spaces
		printf( "%16s %6i %6i\n", test_strings[i], index, probe );
	}

	//
	// calculate table load here
	//
	float load = 0;
	load = loadcalc(NUM_TEST_KEYS, HASH_TABLE_SIZE_M);
	printf("table load: ");
	printf("%f\n", load);

	return 0;
}
