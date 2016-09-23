#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "ClientADT.h"

// This is the struct that stores the properties 
// of the client's address. 
struct address_tag {
    char *name; 
    char *street; 
    char *city_state;
    char *phone; 
};

// This is the struct that stores the properties 
// of the client's preference.
struct preference_tag {
    char *min_BedRoom;
    char *min_BathRoom;
    char *min_SqrFt;
    char *max_price; 

};
 // This is the struct that stores the properties 
// of the client.
struct client_tag {
    char *id; 
    int temp;
    Address  address;
    Preference  pref; 

};


// A helper method for malloc and coping the string. 
char * initString(char * toInit){
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

// initialize client's address
void initClientAddress(Client  this, Address address){
	this->address  = address == NULL ? (Address)malloc(sizeof(struct address_tag)) : address;	
}


// initialize client preference
void initClientPreference(Client this, Preference preference){
	this->pref = preference  == NULL ? (Preference)malloc(sizeof(struct preference_tag)):preference;
}


// allocate memory for a structure variable containing all list components
Client createClient(char * id, Address address, Preference preference){
	Client client = (struct client_tag * )malloc(sizeof(struct client_tag));
	client->id = initString(id);
	client->address = address;
	if(address == NULL){
		client->address = (Address)malloc(sizeof(struct address_tag));
	}
	client->pref = preference;
	if(preference == NULL){
		client->pref = (Preference)malloc(sizeof(struct preference_tag));
	}
	return client;
}


// set the name of the client
void setClientName(Client this, char * name){
	if(this->address == NULL)
		initClientAddress(this, NULL);
	this->address->name = initString(name);
}

// set the street for the client
void setClientStreet(Client this, char * streetAddress){
	if(this->address == NULL)
		initClientAddress(this, NULL);
	this->address->street = initString(streetAddress);
}

// set the city and state for the client. 
void setClientCityAndState(Client this, char * city_state){
	if(this->address == NULL)
		initClientAddress(this, NULL);
	this->address->city_state = initString(city_state);	
}

// set the phone number for the client. 
void setClientPhone(Client this, char * phone){
	if(this->address == NULL)
		initClientAddress(this, NULL);
	this->address->phone = initString(phone);	
}	

// print out the info for each client. 
char * clientToString(Client client){
	//printf("Client id:%s, Name: %s, Street: %s, City:%s, Phone:%s",client->id, client->address->name, client->address->street, client->address->city_state, client->address->phone);
}

// set client's preference
void setClientPreference(Client client, char *bedVar, char * bathVar, char * sqrVar, char * prVar){
		
		client->pref->min_BedRoom = initString(bedVar);
		client->pref->min_BathRoom = initString(bathVar);
		client->pref->min_SqrFt = initString(sqrVar);
		client->pref->max_price = initString(prVar);
		//printf("Client min br = %s, bd = %s, bva = %s, sqv = %s, prv = %s\n",client->pref->min_BedRoom, client->pref->min_BathRoom, client->pref->min_SqrFt, client->pref->max_price);


}
// return the size of the struct. 
int get_Client_Struct_Size(){
    return sizeof(struct client_tag);
}

// return the client id. 
char *  getClientId(Client this){
	return this->id;
}

// return the name of the client. 
char * getClientName(Client client){
	return client->address->name;
}

// return the street that the client is currently living. 
char * getClientStreet(Client client){
	return client->address->street;
}	

// return the city and state that the client is currently living. 
char * getClientCityAndState(Client client){
	return client->address->city_state;
}

// return the client's phone number. 
char * getClientPhone(Client client){
	return client->address->phone;
}

// return the client's preferred number of bedroom. 
char * getClientPreferredNumberOfBedrooms(Client client) {
	return client->pref->min_BedRoom;
}

//return the client's minimum number of bathroom.
char * getClientPreferredNumberOfBathrooms(Client client) {
	return client->pref->min_BathRoom;
}

// return the client's preferred square footage. 
char * getClientPreferredNumberOfSquareFootage(Client client) {
	return client->pref->min_SqrFt;
}

// return the client's preferred price.
char * getClientPreferredNumberOfPrice(Client client) {
	return client->pref->max_price;
}



