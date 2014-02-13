#include <stdio.h>

#define kSequenceInputFilePath "/Users/bernardeverson/Desktop/Research/Koder Lab/4 Helix Bundle/TPChargeScreening/sequence-input.data"

// this method gives the incremental charge to add to 
// the total charge 
int incrementalChargeForResidue(char residue) {
	int charge = 0; 
	
	// positively charged residues
	if (residue == 'R' || residue == 'K') {
		charge = 1;
	}
	else if (residue == 'E') { // negative residues
		charge = -1;
	}
	
	// all others are neutral
	return charge;
	
}

int main (int argc, const char * argv[]) {

	FILE * input_data_file;
	char * input_file_path = kSequenceInputFilePath;

	// show an error if file at path can't be opened
	if ((input_data_file = fopen(input_file_path, "r")) == NULL) {
		printf("\nError opeining file at path: %s\n", input_file_path);
	}

	char current_char;
	
	// an int to keep track of the charge of the helix
	int charge = 0;
	
	while (!feof(input_data_file)) {
		
		current_char = fgetc(input_data_file);

		charge += incrementalChargeForResidue(current_char);
		
	}
	
	printf("Total charge of input sequence is %d", charge);
	
	fclose(input_data_file);
	
    return 0;
}
