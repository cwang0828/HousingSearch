
#ifndef HOUSEADT_H
#define HOUSEADT_H

typedef struct house_tag * House; 

House createHouse(char * mls, char *street, char *city, char *zip, char *num_BedRoom, char *num_BathRoom, char *sqrFt,char *price);

char * getMLS(House house);
char * getStreet(House house);
char * getCity(House house);
char * getZip(House house);
char * getBedroom(House house);
char * getBathroom(House house);
char * getSquareFoot(House house);
char * getPrice(House house);
int get_House_Struct_Size();

void setHouseList(House house,char * mls, char *street, char *city, char *zip, char *num_BedRoom, char *num_BathRoom, char *sqrFt,char *price);

#endif
