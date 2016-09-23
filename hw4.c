
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "listADTgen.h"
#include "ClientADT.h"

#include "HouseADT.h"
#include <ctype.h>

/**
    Name: Hsin-Jung Wang (Cindy)
    TCSS 333 
    Assignment: #4
    NetID: 1260340
*/

// This is the compare method to be used for listADTgen.c
int compare(int *a, int *b) {
    short int toReturn = 0; 
    if(*a < *b){
	toReturn = -1; 
    } else if (*a > *b) {
	toReturn = 1; 
    }
    return toReturn; 
}



int main(void) {

     // read the clients.txt file. 
    FILE *reads;
    int numClients = 0;
    reads = fopen("clients.txt", "r");

    int index = 0; 
    int toDo = 0; 
    int lineNumber = 0;
    char inputLine[100];
    char *str = malloc(sizeof(char) * 100);
    int charactersToOmit = 0;

    Client *client;

    if(reads == NULL) {
        perror("Error"); // when there is no clients.txt
        return 1; 
    } else {
        // count the number of lies in the file
        int lines = 0;
        int ch = 0;  
        while(!feof(reads)) {
            ch = fgetc(reads);
            if(ch == '\n') {
                lines++; 
            }
        }

	rewind(reads);
	numClients = lines /5; // The number of clients
	client = (Client)malloc(sizeof(Client) * numClients);
        int whichProperty = -1;

	// read in the text file line by line
	while(fgets(inputLine, sizeof(inputLine),reads)!=NULL){
	    strcpy(str, inputLine);

	    // just in case there are empty lines in the end.
	    if(index >= numClients){
		break;
	    }	
	    whichProperty = lineNumber % 5;

	    // selects 
	    switch(whichProperty){
		case 0: // create the client object
			client[index] = createClient(inputLine, NULL, NULL);
			break;

		// stores client's name
		case 1: setClientName(client[index], inputLine);
			break;

		// stores client's street info
		case 2: setClientStreet(client[index], inputLine);	
			break;		
		// stores client's city and state info
		case 3: setClientCityAndState(client[index], inputLine);
			break;
		// stores client's phone number
		case 4:setClientPhone(client[index], inputLine);
			clientToString(client[index]);
			index++;
			break;		
	     }
	    ++lineNumber;
	}
	fclose(reads);
    }


  // read the preference.txt file
    FILE *readPref; 
    int numPreference = 0;
    Preference *preference; 
    const char * space = " ";
    readPref = fopen("preferences.txt", "r");

    int indexPref = 0; 
    char *strPref = malloc(sizeof(char) * 100);
    int modePref = 0; 
    int i = 0;
    char *tempStr= malloc(sizeof(char) * 100);; 
    int linesPref = 0;
    int chPref = 0;  
    char inputLinePref[100];

    char bedVar[10]; 
    char bathVar[10];
    char sqrVar[10];
    char prVar[10];

    // when there is no preference.txt
    if(readPref == NULL) {
        perror("Error"); 
	return 1; 
    } else {
        // read from preference.txt
        // count the number of lies in the file
        while(!feof(readPref)) {
            chPref = fgetc(readPref);
            if(chPref == '\n') {
                linesPref++; 
            }
        }

	rewind(readPref);
	numPreference = linesPref / 2; // count the number of preference. 

        preference = (Preference *) malloc(sizeof(Preference) * (numPreference));

    
	while(fgets(inputLinePref, sizeof(inputLinePref),readPref)!=NULL){
 	    strcpy(strPref, inputLinePref);
	   // read in the id first to check where in the array is the id being stored  
           if(modePref == 0) {
                indexPref = 0; 
                strcpy(tempStr,strPref); 
                // find the index of the array based on the id. 
                for(i = 0; i < index; i++) {
		    if(strcmp(getClientId(client[i]), tempStr) == 0) {
			indexPref = i;
			break; 
                    } 
		}
		modePref=1;
	    // use the index to find the right client and match the prefernece to the previously stored info.
	    } else {
		sscanf(strPref, "%s %s %s %s", bedVar, bathVar, sqrVar, prVar);
		setClientPreference(client[indexPref], bedVar, bathVar, sqrVar, prVar);
		modePref = 0;   
           } 
	}
    }

    close(readPref); 

    // read house.csv file. 
    FILE *readHouse; 
    int numHouse = 0;
    House *house; 
    readHouse = fopen("houses.csv", "r");
    int chHouse =0;
    char inputLineHouse[1000];
    char *strHouse = malloc(sizeof(char) * 1000);
    const char *s =",";
    char *tempVar; 
    int element =0; 
    int indexHouse = 0; 

    int hmodePref = 0; 
    int hindexPref = 0; 

    // process each line that is separated by comma
    char hnum1[10];
    char hnum2[50];
    char hnum3[50];
    char hnum4[50];
    char hnum5[50];
    char hnum6[50];
    char hnum7[50];
    char hnum8[50];

    int hcount = 0;
    if(readHouse == NULL) {
        perror("Error"); // when there is no house.csv
	return 1;
     } else {
	while(!feof(readHouse)) {
            chHouse = fgetc(readHouse);
            if(chHouse == '\n') { // figure out how many houses in total 
                numHouse++; 
            }
        }
	rewind(readHouse);
	house = (House *) malloc(sizeof(House) * (numHouse));

	// read in the file line by line
	// for each line, use scanf to separate the text.    
    	while(fgets(inputLineHouse, sizeof(inputLineHouse),readHouse)!=NULL){
	    strcpy(strHouse, inputLineHouse);
	    sscanf(strHouse, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", hnum1, hnum2, hnum3, hnum4, hnum5, hnum6, hnum7, hnum8); 
	    house[hcount] = createHouse(hnum1, hnum2, hnum3, hnum4, hnum5, hnum6, hnum7, hnum8);
	    hcount++; 
	}
        fclose(readHouse);
    }

    ListType clientList;
    ListType houseList;
    clientList = create(get_Client_Struct_Size(), compare); 
    houseList = create(get_House_Struct_Size(), compare); 

    // store the client info into the arraylist (clientlist). 
    int cListIndex, hListIndex = 0; 
    for(cListIndex = 0; cListIndex < numClients; cListIndex++) {
	push(clientList, client[cListIndex]); 
    }
 
    // store the house info into the arraylist(houselist).
    for(hListIndex = 0; hListIndex < numHouse; hListIndex++) {
	push(houseList, house[hListIndex]); 
    }

    // write to clientView.csv file
    FILE *fp;
    fp = fopen("clientView.csv", "w");
    fprintf(fp, "Client ID,Name,Phone Number, , ,MLS,Street Address,City,Zip,Bedroom,Bathroom, Sq Footage, Price");
    fprintf(fp,"\r\n");

    int clientlistsize, houselistSize = 0; 

    clientlistsize = size_is(clientList); 
    houselistSize = size_is(houseList); 

    int ct, r1,r2;

    for(r1= 0; r1 <clientlistsize; r1++) {
	ct = 0; 
	Client tmpclient = ((Client) get(r1, clientList)); 
	fprintf(fp, "%s,%s,%s,,,", getClientId(tmpclient),getClientName(tmpclient), getClientPhone(tmpclient)); 

	for(r2 = 0; r2 < houselistSize; r2++) {
	    House tmphouse = ((House) get(r2, houseList)); 
	    // if current row's info is from the previous client (previous row)
	    if(getBedroom(tmphouse) >= getClientPreferredNumberOfBedrooms(tmpclient) && getBathroom(tmphouse) >= getClientPreferredNumberOfBathrooms(tmpclient) && getSquareFoot(tmphouse) >= getClientPreferredNumberOfSquareFootage(tmpclient) && getPrice(tmphouse) <= getClientPreferredNumberOfPrice(tmpclient)) {
		if(ct>0) {
		   fprintf(fp,",,,,,");
		}
		

		/*printf("%s,%s,%s,%s,%s,%s,%s,%s\n", getMLS(house[r2]),getStreet(house[r2]),getCity(house[r2]),getZip(house[r2]), getBedroom(house[r2]), getBathroom(house[r2]), getSquareFoot(house[r2]),getPrice(house[r2]));*/ 
		fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s\n", getMLS(house[r2]),getStreet(house[r2]),getCity(house[r2]),getZip(house[r2]), getBedroom(house[r2]), getBathroom(house[r2]), getSquareFoot(house[r2]),getPrice(house[r2]));

		//printf("the getter for street is %s", getStreet(tmphouse));
		/*fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s\n", getMLS(tmphouse),getStreet(tmphouse),getCity(tmphouse),getZip(tmphouse), getBedroom(tmphouse), getBathroom(tmphouse), getSquareFoot(tmphouse),getPrice(tmphouse));*/
	     ct++;
	    }
	}
    }

    fclose(fp); 

    // writing to houseView.csv file
    FILE *hfp = fopen("houseView.csv", "w");
    int r3,r4,hct;
    fprintf(hfp, "MLS,Street Address,City,Zip,Bedroom,Sq Footage,Price,,Client ID,Name,Phone Number");
    fprintf(hfp,"\r\n");
    for(r3 = 0; r3 <houselistSize;r3++){
	hct = 0; 
	    House tmphouse = ((House) get(r3, houseList)); 
	    for(r4 = 0; r4 < clientlistsize; r4++) {
		Client tmpclient = ((Client) get(r4, clientList));
		if(getBedroom(tmphouse) >= getClientPreferredNumberOfBedrooms(tmpclient) && getBathroom(tmphouse) >= getClientPreferredNumberOfBathrooms(tmpclient) && getSquareFoot(tmphouse) >= getClientPreferredNumberOfSquareFootage(tmpclient) && getPrice(tmphouse) <= getClientPreferredNumberOfPrice(tmpclient)) {
		    if(hct ==0) {
			fprintf(hfp, "%s,%s,%s,%s,%s,%s,%s,%s,,",getMLS(house[r4]), getStreet(house[r4]), getCity(house[r4]), getZip(house[r4]), getBedroom(house[r4]), getBathroom(house[r4]), getSquareFoot(house[r4]), getPrice(house[r4]));

			/*fprintf(hfp, "%s,%s,%s,%s,%s,%s,%s,%s,,",getMLS(tmphouse), getStreet(tmphouse), getCity(tmphouse), getZip(tmphouse), getBedroom(tmphouse), getBathroom(tmphouse), getSquareFoot(tmphouse), getPrice(tmphouse));*/

		    }else if (hct >0) {
		 	fprintf(hfp, ",,,,,,,,,");
		    }
		    fprintf(hfp, "%s,%s,%s\r\n",getClientId(tmpclient), getClientName(tmpclient), getClientPhone(tmpclient));
		    hct++;
		}
	    }
    }
    


    return 0; 
}

