#include <iostream>
using namespace std;
//First pointer points to the first item &
//last pointer points to the last item of the array
//add all the items stored between 2 pointers (both inclusive) and return the total
int add(int *firstp, int *lastp){
    int total = 0;
    while(firstp < lastp){
        total = total + *firstp;
        firstp++;
    }
    //OR if you do not want to mess with pointer parameters
    for(int *ip = firstp; ip <= lastp; ip++){
        total = total + *ip;
    }
}
//Get user input and fill the whole range
// of the array indicated by first and last pointers.

void fillUp(int *firstp, int *lastp){

    for(int *ip = firstp; ip < lastp; ip++){
        cout << "Enter a value" << endl;
        cin >> *ip;
    }
    cout << "\nHere are the values you entered\n" ;
    for(int *ip = firstp; ip < lastp; ip++){
        cout << *ip;
    }
}

int * linearSearch(int *firstp, int * lastp, int value){
    for(int *ip = firstp; ip < lastp; ip++){
        if(*ip = value){
            //item has been found; so no need to search further
            return ip; //returns the pointer to where the value is
        }else{
            //item at location pointed by ip did not match with value
            //we need to move to next place and compare with value
        }
    }
    //control comes here only when all items have been compared against value
    // and none of those items matched
    //  which means value is not inside the array
    //  so return NULL
    return NULL;
    //NOTE To find frequency of a value in an array, code is similar to linearSearch ;
    // additionally, a counter (initialized with 0) to keep track of number of times a match happens is needed.
    //finally return the counter's value
}

//First pointer points to the first item,
//last pointer points to the last item of the array
//split the array into 2 halves, compute total for each part
//check whether total for both parts are equal, return true if they match
//false otherwise.
bool diffHalves(int *firstp, int *lastp) {
	int *midp = firstp + (lastp-firstp)/2;
	int total1 = 0, total2 = 0;

	for(int *ip=firstp; ip<=midp; ip++){
        total1 = total1 + *ip;
        //cout << "adding " << *i << " making total1 = " << total1 << endl;
	}
	for(int *ip=midp+1; ip<=lastp; ip++){
        total2 = total2 + *ip;
        //cout << "adding " << *i << " making total2 = " << total2 << endl;
	}
	cout << "total1 = " << total1 << " and total2 = " << total2 << endl;
	return (total1 == total2);
	//OR
    //	if(total1 == total2){
    //        return true;
    //	}else{
    //        return false;
    //	}
}

//First pointer points to the first item,
//last pointer points to the last item of the array
//add all the items stored in even positions in the array (based on firstp)
//add all the items stored in odd positions in the array
//check whether both totals are equal, return true if they match
//return false otherwise.
bool diffOddEven(int *firstp, int *lastp) {
	int total1 = 0, total2 = 0;
	for(int *ip=firstp; ip<=lastp; ip+=2){
        total1 = total1 + *ip;
        //cout << "adding " << *i << " making total1 = " << total1 << endl;
	}
	for(int *ip=firstp+1; ip<=lastp; ip+=2){
        total2 = total2 + *ip;
        //cout << "adding " << *i << " making total2 = " << total2 << endl;
	}
	cout << "total1 = " << total1 << " and total2 = " << total2 << endl;
	return (total1 == total2);
}

//code to compare 2 strings - both are NULL terminated
//return 0 if both strings are of same length & contents are exactly same
//return +ve value if first will appear after second in the dictionary order: super, great
//return -ve value if it is the other way around.
int compareStrings(char *firstp, char *secondp) {
	char *fp = firstp;
	char *sp = secondp;
	while (*fp == *sp) {
		if (*fp == NULL)
			return 0;
		fp++;
		sp++;
	}
	return *fp - *sp;	//fun fund
}


int main(){
    int numbers[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(numbers) / sizeof(int);
    cout << "# of elements in the array : " << n << endl;

    int *fp = numbers; //OR int *fp = &numbers[0];
    int *lp = fp + (n-1);

    cout << "Total of all elements " << add(fp, lp);

    //fillUpfp, lp); //commenting as this will fill up the array numbers with
            // user entered values

    if(linearSearch(fp, lp, 30)){
        cout << "Found 30" << endl;
    }else{
        cout << "Did not find 30" << endl;
    }
    if(linearSearch(fp, lp, 90)){
        cout << "Found 90" << endl;
    }else{
        cout << "Did not find 90" << endl;
    }

    int numbers1[] = {10, 20, 30, 40, 50, 60};
    int numbers2[] = {10, 20, 30, 40, 50};
    int numbers3[] = {10, 20, 30, 10, 20, 30};
    int numbers4[] = {10, 20, 30};

    int n = sizeof(numbers3)/sizeof(int); //CHANGE any of the other array names
    cout << "# of items in array = " << n << endl;
    int *fp = &numbers3[0]; //or int *fp = numbers3; // NOTE : make sure the array name in finding size of array as well as in this line is the same
    int *lp = fp + (n-1);

    cout << add(fp, lp) << endl;
    cout << (diffHalves(fp, lp) ? "Same Total on both portions \n" : "Different on both portions\n") ;
    cout << (diffOddEven(fp, lp) ? "Same Total on odd & even portions \n" : "Different on odd & even portions\n") ;
    //fill(fp, lp); //commenting as this will fill up the array numbers with user entered values
    cout << (linearSearch(fp, lp, 30) ? "Found\n" : "Not found\n");
    cout << (linearSearch(fp, lp, 80) ? "Found\n" : "Not found\n");
    cout << "30 found " << frequency(fp, lp, 30) << " times\n";
    cout << "80 found " << frequency(fp, lp, 80) << " times\n";

    char ui1[100], ui2[100];
    cin >> ui1 >> ui2;
    if(compareStrings(ui1, ui2) > 0){
        cout << ui1 << " appears after " << ui2 << endl;
    }else{
        cout << ui2 << " appears after " << ui1 << endl;
    }
}
