#include <stdio.h>
#include <string.h>

struct PERSON {
    int id;
    char name[50];
    char location[50];
} people[100];

int main() {
    int n, i, j;
    char location[50];

    printf("Enter the number of people: ");
    scanf("%d", &n);

    // Input details for each person
    for (i = 0; i < n; i++) {
        printf("Enter details for person %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &people[i].id);

        printf("Name: ");
        scanf(" %[^\n]%*c", people[i].name); // to read string with spaces

        printf("Location: ");
        scanf(" %[^\n]%*c", people[i].location);
    }

    printf("\nEnter the location to find the network: ");
    scanf(" %[^\n]%*c", location);

    printf("\nPeople from the location '%s':\n", location);
    printf("ID\tName\n");

    // Find and print people from the same location
    for (i = 0; i < n; i++) {
        if (strcmp(people[i].location, location) == 0) {
            printf("%d\t%s\n", people[i].id, people[i].name);
        }
    }

    return 0;
}
