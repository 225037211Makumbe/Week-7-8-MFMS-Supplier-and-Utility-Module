
#include <stdio.h>

#define MAX_SUPPLIERS 100
#define VAT_RATE 0.15

/* Supplier structure */
struct Supplier {
    int supplierID;
    char name[50];
    char contact[20];
};

struct Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

/* Function declarations */
void addSupplier(void);
void displaySupplier(void);
void searchSupplier(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void displayMenu(void);

int main(void) {
    int choice;
    float amount, basic, housing, transport;
    float revenue, expenses;

    do {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addSupplier();
                break;

            case 2:
                displaySupplier();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                printf("Enter amount: NAD ");
                scanf("%f", &amount);

                printf("VAT (15%%): NAD %.2f\n",
                       calculateVAT(amount));

                printf("Total including VAT: NAD %.2f\n",
                       amount + calculateVAT(amount));
                break;

            case 5:
                printf("Enter basic salary: NAD ");
                scanf("%f", &basic);

                printf("Enter housing allowance: NAD ");
                scanf("%f", &housing);

                printf("Enter transport allowance: NAD ");
                scanf("%f", &transport);

                printf("Total Salary: NAD %.2f\n",
                       calculateSalary(basic, housing, transport));
                break;

            case 6:
                printf("Enter revenue: NAD ");
                scanf("%f", &revenue);

                printf("Enter expenses: NAD ");
                scanf("%f", &expenses);

                printf("Budget Balance: NAD %.2f\n",
                       calculateBudget(revenue, expenses));

                if (calculateBudget(revenue, expenses) >= 0) {
                    printf("Status: Budget Surplus\n");
                } else {
                    printf("Status: Budget Deficit\n");
                }
                break;

            case 7:
                printf("Exiting MFMS. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");

    } while (choice != 7);

    return 0;
}

/* Display menu */
void displayMenu(void) {
    printf("========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
    printf("========================================\n");
}

/* Add supplier */
void addSupplier(void) {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Supplier storage is full.\n");
        return;
    }

    printf("\nEnter Supplier ID: ");
    scanf("%d", &suppliers[supplierCount].supplierID);

    printf("Enter Supplier Name: ");
    scanf(" %49[^\n]", suppliers[supplierCount].name);

    printf("Enter Contact Number: ");
    scanf("%19s", suppliers[supplierCount].contact);

    supplierCount++;

    printf("Supplier added successfully!\n");
}

/* Display all suppliers */
void displaySupplier(void) {
    int i;

    if (supplierCount == 0) {
        printf("No suppliers available.\n");
        return;
    }

    printf("\n----- SUPPLIER DETAILS -----\n");

    for (i = 0; i < supplierCount; i++) {
        printf("\nSupplier ID: %d\n",
               suppliers[i].supplierID);
        printf("Supplier Name: %s\n",
               suppliers[i].name);
        printf("Contact Number: %s\n",
               suppliers[i].contact);
    }
}

/* Search supplier using ID */
void searchSupplier(void) {
    int id, i;
    int found = 0;

    printf("Enter Supplier ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < supplierCount; i++) {
        if (suppliers[i].supplierID == id) {
            printf("\nSupplier Found!\n");
            printf("Supplier ID: %d\n", suppliers[i].supplierID);
            printf("Supplier Name: %s\n", suppliers[i].name);
            printf("Contact Number: %s\n", suppliers[i].contact);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Supplier not found.\n");
    }
}

/* Calculate VAT at 15% */
float calculateVAT(float amount) {
    return amount * VAT_RATE;
}

/* Calculate total salary */
float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

/* Calculate budget balance */
float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}
