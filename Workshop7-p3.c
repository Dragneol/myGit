/*
o	Develop a C-program that allows user:
-	Adding a new soft drink
-	Printing out items which belong to a known make.
-	Printing out items whose volumes are between v1 and v2 ( integers)  
-	Printing the list in ascending order based on volumes then prices.
*/

#include <stdio.h>
#include <stdlib.h>
#include "trim.c"

#define MAXN 100
#define NAME_LENGTH 22
#define MAKE_LENGTH 22
#define ENTRY_FORMAT "%22s %22s %10d %10d %10d\n"

typedef struct {
    char * name, * make;
    int volume, price, duration;
} softdrink;

void add(softdrink * drinks, int * size, softdrink drink) {
    drinks[(*size)++] = drink;
}

void printHeader() {
    printf("%22s %22s %10d %10d %10d", "Name", "Make", "Volume", "Price", "Duration");
}

void printAnItem(softdrink * drinks, int pos) {
    printf(ENTRY_FORMAT, drinks[pos].name, drinks[pos].make, drinks[pos].volume, drinks[pos].price, drinks[pos].duration);
}

int search(softdrink * drinks, int size, char * make, int start) {
    int i;
    for (i = start; i < size; ++i)
        if (cistrstr(drinks[i].make, make))
            return i;
    return -1;
}

int searchVolume(softdrink * drinks, int size, int vMin, int vMax, int start) {
    int i;
    for (i = start; i < size; ++i)
        if (drinks[i].volume >= vMin && drinks[i].volume <= vMax)
            return i;
    return -1;
}

void sortVolumeAndPrice(softdrink ** drinks, int size) {
    int i, j;
    softdrink * tmp;
    for (i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (j = i + 1; j < size; ++j)
            if (drinks[j]->volume > drinks[minIndex]->volume || (drinks[j]->volume == drinks[minIndex]->volume && drinks[j]->price > drinks[minIndex]->price)) 
                minIndex = j;
        tmp = drinks[i];
        drinks[i] = drinks[minIndex];
        drinks[minIndex] = tmp;
    }
}

void printVolumeAndPrice(softdrink * drinks, int size) {
    softdrink ** sorted = (softdrink**)malloc(size*sizeof(softdrink*));
    int i;
    for (i = 0; i < size; ++i)
        sorted[i] = &drinks[i];
    sortVolumeAndPrice(sorted, size);
    printHeader();
    for (i = 0; i < size; ++i)
        printf(ENTRY_FORMAT, sorted[i]->name, sorted[i]->make, sorted[i]->volume, sorted[i]->price, sorted[i]->duration);
    free(sorted);
}

int interactReadInt(const char * prompt) {
    int count, ret;
    do {
        printf("%s", prompt);
        count = scanf("%d", &ret);
        getchar();
    } while (count < 1);
    return ret;
}

int get(const char * prompt, int min, int max) {
    int ret;
    do {
        ret = interactReadInt(prompt);
    } while (ret < min || ret > max);
    return ret;
}

int getUserChoice() {
    printf("\nList of softdrinks\n");
    printf("1. Add a new softdrink\n");
    printf("2. Search items by make\n");
    printf("3. Search items by volume range\n");
    printf("4. Print the list order by volume then price\n");
    printf("5. Quit\n");
    return get("Choice: ", 1, 5);
}

int main() {
    softdrink * drinks = (softdrink*)malloc(MAXN*sizeof(softdrink));
    int size = 0;
    char makeBuffer[MAKE_LENGTH];
    int choice;
    do {
        choice = getUserChoice();
        switch (choice) {
            case 1: {
                if (size == MAXN) {
                    printf("List is full!\n");
                    break;
                }
                softdrink drink;
                printf("Enter softdrink's name: ");
                drink.name = (char*)malloc(NAME_LENGTH*sizeof(char));
                fgets(drink.name, NAME_LENGTH, stdin);
                captalize(trim(drink.name));
                
                printf("Enter softdrink's make: ");
                drink.make = (char*)malloc(MAKE_LENGTH*sizeof(char));
                fgets(drink.make, MAKE_LENGTH, stdin);
                captalize(trim(drink.make));
                
                drink.volume = interactReadInt("Enter softdrink's volume: ");
                drink.price = interactReadInt("Enter softdrink's price: ");
                drink.duration = interactReadInt("Enter softdrink's duration: ");
               
                add(drinks, &size, drink);
                printf("Added\n");
                break;
            }
            case 2: {
                if (size == 0) {
                    printf("List is empty!\n");
                    break;
                }
                printf("Enter softdrink's make to search: ");
                fgets(makeBuffer, MAKE_LENGTH, stdin);
                captalize(trim(makeBuffer));
                int pos = -1, searchCount = 0;
                printHeader();
                do {
                    pos = search(drinks, size, makeBuffer, pos + 1);
                    if (pos >= 0) {
                        printAnItem(drinks, pos);
                        searchCount += 1;
                    }
                } while (pos >= 0);
                if (searchCount == 0)
                    printf("No item found!\n");
                break;
            }
            case 3: {
                int vMin = interactReadInt("Enter volume low range: ");
                int vMax = interactReadInt("Enter volume high range: ");
                printHeader();
                int pos = -1, searchCount = 0;
                do {
                    pos = searchVolume(drinks, size, vMin, vMax, pos + 1);
                    if (pos >= 0) {
                        printAnItem(drinks, pos);
                        searchCount += 1;
                    }
                } while (pos >= 0);
                if (searchCount == 0)
                    printf("No item found!\n");
                break;
            }
            case 4:
                printVolumeAndPrice(drinks, size);
                break;
            case 5:
                printf("Quitting ...\n");
        }
    } while (choice >= 0 && choice < 5);
    return 0;
}
