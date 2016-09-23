#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "HouseADT.h"


// This is the struct that stores the properties 
// for each of the struct. 
struct house_tag {
    char *mls;
    char *street;
    char *city;
    char *zip;
    char *num_BedRoom;
    char *num_BathRoom;
    char *sqrFt; 
    char *price; 
};

// A helper method for malloc and coping the string. 
char * hinitString(char * toInit){
	char * result = (char *)malloc(sizeof(char) * (strlen(toInit) + 1));
	strcpy(result, toInit);
	int i = 0;
	for(i =0; i < strlen(result); i++) {
	    if(result[i] == '\n' || result[i] == '\r') {
		result[i] = '\0';
	    }
	}

	return result;
}

// allocate memory for a structure variable containing all list components
House createHouse(char * mls, char *street, char *city, char *zip, char *num_BedRoom, char *num_BathRoom, char *sqrFt,char *price){
	House house = (struct house_tag * )malloc(sizeof(struct house_tag));
	house->mls = hinitString(mls);
        //house->street = malloc(sizeof(char) * strlen(street));
        //house->street = street;
	house->street = hinitString(street);
	house->city = hinitString(city);
	house->zip = hinitString(zip);
	house->num_BedRoom = hinitString(num_BedRoom);
	house->num_BathRoom = hinitString(num_BathRoom);
	house->sqrFt = hinitString(sqrFt);
	house->price = hinitString(price);

	return house;
}


char * getMLS(House house) {
	return house->mls;
}

// return the street name
char * getStreet(House house) {
	return house->street;
}

// return the number of city. 
char * getCity(House house) {
	return house->city; 
}

// return the zip
char * getZip(House house) {
	return house->zip;
}

// return the bedroom number
char * getBedroom(House house) {
	return house->num_BedRoom;
}

// return the bathroom number
char * getBathroom(House house) {
	return house->num_BathRoom;
}

// return the square footage
char * getSquareFoot(House house){
	return house->sqrFt;
}

// return the price 
char * getPrice(House house){
	return house->price;
}

// return the size of the struct.
int get_House_Struct_Size(){
    return sizeof(struct house_tag);
}

// allocate each of the variables inside the house struct dynamically 
void setHouseList(House house,char *  hnum1,char * hnum2, char *hnum3,char * hnum4,char * hnum5, char *hnum6, char *hnum7, char *hnum8){
	    house->mls=hinitString(hnum1); 
	    house->street=hinitString(hnum2); 
	    house->city=hinitString(hnum3);
	    house->zip=hinitString(hnum4); 
	    house->num_BedRoom=hinitString(hnum5); 
	    house->num_BathRoom=hinitString(hnum6); 
	    house->sqrFt=hinitString(hnum7);
	    house->price=hinitString(hnum8); 
}



