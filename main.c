#include <stdio.h>
#include <string.h>

struct Donor {
    char name[50];
    int age;
    char bloodGroup[5];
    char phone[15];
};

int main() {
    struct Donor d;
    FILE *fp;
    int n, i;
    char searchGroup[5];
    int found = 0;

    fp = fopen("donors.txt", "w");
    if (fp == NULL) {
        printf("File cannot be opened\n");
        return 1;
    }

    printf("Enter number of donors: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of Donor %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", d.name);

        printf("Age: ");
        scanf("%d", &d.age);

        printf("Blood Group: ");
        scanf("%s", d.bloodGroup);

        printf("Phone Number: ");
        scanf("%s", d.phone);

        fprintf(fp, "%s %d %s %s\n", d.name, d.age, d.bloodGroup, d.phone);
    }

    fclose(fp);

    fp = fopen("donors.txt", "r");
    if (fp == NULL) {
        printf("File cannot be opened\n");
        return 1;
    }

    printf("\nEnter blood group to search: ");
    scanf("%s", searchGroup);

    printf("\n--- Donor Details ---\n");

    while (fscanf(fp, "%s %d %s %s", d.name, &d.age, d.bloodGroup, d.phone) != EOF) {
        if (strcmp(d.bloodGroup, searchGroup) == 0) {
            printf("\nName        : %s", d.name);
            printf("\nAge         : %d", d.age);
            printf("\nBlood Group : %s", d.bloodGroup);
            printf("\nPhone       : %s\n", d.phone);
            found = 1;
        }
    }

    if (found == 0) {
        printf("\nNo donor found for blood group %s\n", searchGroup);
    }

    fclose(fp);
    return 0;
}