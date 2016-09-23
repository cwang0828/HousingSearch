
#ifndef CLIENTADT_H
#define CLIENTADT_H

typedef struct address_tag * Address; 
typedef struct preference_tag * Preference; 
typedef struct client_tag * Client; 

Client createClient(char * id, Address  address, Preference preference);

void setClientName(Client  client, char * name);
void setClientCityAndState(Client  client, char * cityAndState);
void setClientStreet(Client  client, char * street_address);
void setClientPhone(Client  client, char * phone);

void setClientPreference(Client client, char *minBedroom, char * minBathroom, char * minSquareFeet, char * maxPrice);

char * getClientId(Client client);
char * getClientName(Client client);
char * getClientAddress(Client client);
char * getClientState(Client client);
char * getClientPhone(Client client);

char * getClientPreferredNumberOfBedrooms(Client client);
char * getClientPreferredNumberOfBathrooms(Client client);
char * getClientPreferredNumberOfSquareFootage(Client client);
char * getClientPreferredNumberOfPrice(Client client);
int get_Client_Struct_Size();

char * clientToString(Client client);

char * getClientId(Client client);

#endif




