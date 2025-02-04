#ifndef FONCTION_NJAMPOU
#define FONCTION_NJAMPOU

//This describes each entry of an index in the hash table
typedef struct student{
    char matriculeNJ[8];
    char nameNJ[20];
    char surnameNJ[20];
    int ageNJ;
}studentNJ;

//This then describes that the hash table has a given size, and each index has an entry
typedef struct HashTableNJ{
    int sizeNJ;
    studentNJ**studNJ;
}HashTableNJ;

void getmatriculeNJ(char*matriculeNJ);
//initialising the hash table
HashTableNJ *initHashTableNJ(int size);
int hashkeyNJ(char*strNJ);

//Insertion into the table
void insertNJ(HashTableNJ *tableNJ,studentNJ*EstudNJ);

studentNJ*searchstudent(HashTableNJ*tableNJ, char* matriculeNJ);

studentNJ *CreateEntryNJ(char*matriculNJ,char*nameNJ,char*surnameNJ,int ageNJ);

void deletestudent(HashTableNJ*tableNJ, char* matriculeNJ);

void editfileNJ(HashTableNJ*tableNJ,char*fileNJ);
void fonction_dommo(int a);

#endif
