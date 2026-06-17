#include <iostream>
#include <iomanip>
using namespace std;

void displayWelcome() {
    cout << "========================================================================================" << endl;
    cout << "\t\t\tWELCOME TO PRESCRIPTION MANAGEMENT SYSTEM" << endl;
    cout << "========================================================================================" << endl;
    cout << "\t\t      This system helps manage patient prescription" << endl;
    cout << "\t\t      and provide detailed reports for each patient." << endl;
}

void patientDetails(string& name, int& age, string& phone) {
    cout << "\nPlease fill in the information below:" << endl;
    cout << "Enter patient name: ";
    getline(cin, name);
    cout << "Enter patient age: ";
    cin >> age;
    while (age <= 0) {
        cout << "AGE UNDEFINED! ENTER PATIENT AGE AGAIN: ";
        cin >> age;
    }
    cin.ignore();
    cout << "Enter phone number: ";
    getline(cin, phone);
}

void displayDiseaseTable() {
    cout << "\nDisease Code Reference Table : " << endl;
    cout << "+------------------+----------------------+----------------+---------------------------+" << endl;
    cout << "|   DISEASE CODE   |    NAME OF DISEASE   |    MEDICINE    |    PRICE PER PILL (RM)    |" << endl;
    cout << "+------------------+----------------------+----------------+---------------------------+" << endl;
    cout << "|        A         |         Flu          |   Paracetamol  |            0.40           |" << endl;
    cout << "+------------------+----------------------+----------------+---------------------------+" << endl;
    cout << "|        B         |         Cold         |   Ibuprofen    |            0.60           |" << endl;
    cout << "+------------------+----------------------+----------------+---------------------------+" << endl;
    cout << "|        C         |       Diabetes       |   metformin    |            0.20           |" << endl;
    cout << "+------------------+----------------------+----------------+---------------------------+" << endl;
    cout << "|        D         |     Hypertension     |   Amlodipine   |            0.50           |" << endl;
    cout << "+------------------+----------------------+----------------+---------------------------+" << endl;
}

void displayDosageTable() {
    cout << "\n+-------------------+----------------------------+" << endl;
    cout << "| Age Group         | Recommended Dosage         |" << endl;
    cout << "+-------------------+----------------------------+" << endl;
    cout << "| Children (0-12)   | Half a pill                |" << endl;
    cout << "| Teenagers (13-19) | One pill                   |" << endl;
    cout << "| Adults (20-59)    | Two pills                  |" << endl;
    cout << "| Seniors (60+)     | One pill (mild dose)       |" << endl;
    cout << "+-------------------+----------------------------+" << endl;
}

void addMedications(char& disease, string& diseaseName, float& pricePerPill, int& totalPills, bool& valid) {
    valid = false;
    while (!valid) {
        cout << "\nEnter disease code [A|B|C|D]: ";
        cin >> disease;

        const string diseaseNames[4] = {"Flu", "Cold", "Diabetes", "Hypertension"};
        const float prices[4] = {0.40, 0.60, 0.20, 0.50};
        const int pills[4] = {10, 15, 30, 30};

        if (disease == 'A' || disease == 'a') {
            diseaseName = diseaseNames[0];
            pricePerPill = prices[0];
            totalPills = pills[0];
            valid = true;
        } else if (disease == 'B' || disease == 'b') {
            diseaseName = diseaseNames[1];
            pricePerPill = prices[1];
            totalPills = pills[1];
            valid = true;
        } else if (disease == 'C' || disease == 'c') {
            diseaseName = diseaseNames[2];
            pricePerPill = prices[2];
            totalPills = pills[2];
            valid = true;
        } else if (disease == 'D' || disease == 'd') {
            diseaseName = diseaseNames[3];
            pricePerPill = prices[3];
            totalPills = pills[3];
            valid = true;
        } else {
            cout << "INVALID INPUT! PLEASE ENTER THE RIGHT CODE." << endl;
            valid = false;
        }
    }
}

void dosageNeed(int age, string& dosage, int& pillsPerDay) {
    if (age >= 0 && age <= 12) {
        dosage = "Half a pill, two times per day";
        pillsPerDay = 1;
    } else if (age >= 13 && age <= 19) {
        dosage = "One pill, two times per day";
        pillsPerDay = 2;
    } else if (age >= 20 && age <= 59) {
        dosage = "Two pills, two times per day";
        pillsPerDay = 4;
    } else if (age >= 60) {
        dosage = "One pill (mild dose)";
        pillsPerDay = 1;
    } else {
        dosage = "Invalid age";
        pillsPerDay = 0;
    }
}

float calculateDuration(int totalPills, int pillsPerDay, int& durationDay, int& day, int& weeks) {
    durationDay = totalPills / pillsPerDay; // Total days the medication will last
    weeks = durationDay / 7;
    day = durationDay % 7;
}

void displayPatientDetails(string name, string phone, string diseaseName, int age) {
    cout << "\n+--------------------------------------------------+" << endl;
    cout << "|                Patient Details                   |" << endl;
    cout << "+--------------------------------------------------+" << endl;
    cout << "  Name                  : " << name << endl;
    cout << "  Phone                 : " << phone << endl;
    cout << "  Age                   : " << age << endl;
    cout << "  Disease               : " << diseaseName << endl;
    cout << "+--------------------------------------------------+" << endl;
}

void displayReceipt(string name, int age, string disease, int totalPills, float pricePerPill, string dosage, float aftertax, int durationDay, int day, int weeks, float tax) {
    cout << fixed << setprecision(2);
    cout << "\n+--------------------------------------------------+" << endl;
    cout << "|                Prescription Receipt              |" << endl;
    cout << "+--------------------------------------------------+" << endl;
    cout << "  Patient Name       : " << name << endl;
    cout << "  Patient Age        : " << age << endl;
    cout << "  Disease            : " << disease << endl;
    cout << "   Medication Details: " << endl;
    cout << "     Total Pills     : " << totalPills << endl;
    cout << "     Price per Pill  : RM" << pricePerPill << endl;
    cout << "     Dosage          : " << dosage << endl;
    cout << "     Total Duration  : " << durationDay << " days (" << weeks << " weeks and " << day << " days)" << endl;
    cout << "     Tax             : RM" << tax << endl;
    cout << "     Total Cost (after tax) : RM" << aftertax << endl;
    cout << "+--------------------------------------------------+" << endl;
}

void displaySummary(float totalRevenue, int patientCount, float maxCost, float minCost) {
    float averageCost = totalRevenue / patientCount;
    cout << "\n+------------------------------------------------------------+" << endl;
    cout << "|                    Summary Report                          |" << endl;
    cout << "+------------------------------------------------------------+" << endl;
    cout << "  Total Prescriptions           : " << patientCount << endl;
    cout << "  Total Revenue (before tax)    : RM" << totalRevenue << endl;
    cout << fixed << setprecision(2);
    cout << "  Average Cost per Prescription : RM" << averageCost << endl;
    cout << "  Highest Prescription Cost     : RM" << maxCost << endl;
    cout << "  Lowest Prescription Cost      : RM" << minCost << endl;
    cout << "+------------------------------------------------------------+" << endl;
}

int main(int argc, char** argv) {
    float totalRevenue = 0;
    int patientCount = 0;
    float maxCost = 0, minCost = 100000000; // Start minCost as a very high value
    int choice;

    displayWelcome();

    do {
        cout << "\nMain Menu :" << endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. Display Summary Report" << endl;
        cout << "3. Display disease and dosage table" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character

        if (choice == 1) {
            string name, phone, diseaseName, dosage;
            int age, totalPills = 0, pillsPerDay, durationDay, day, weeks;
            float pricePerPill = 0.00, totalCost = 0.00, aftertax = 0.00 , tax = 0.00;
            char disease;
            bool valid = false;

            patientDetails(name, age, phone);
            displayDiseaseTable();
            displayDosageTable();

            addMedications(disease, diseaseName, pricePerPill, totalPills, valid);
            dosageNeed(age, dosage, pillsPerDay);

            totalCost = totalPills * pricePerPill;
            tax = totalCost * 0.06;
            aftertax = totalCost + tax;
            totalRevenue += totalCost;

            if (totalCost > maxCost) maxCost = totalCost;
            if (totalCost < minCost) minCost = totalCost;

            patientCount++;
            calculateDuration(totalPills, pillsPerDay, durationDay, day, weeks);
            displayPatientDetails(name, phone, diseaseName, age);
            displayReceipt(name, age, diseaseName, totalPills, pricePerPill, dosage, aftertax, durationDay, day, weeks, tax);
        } else if (choice == 2) {
            if (patientCount > 0) {
                displaySummary(totalRevenue, patientCount, maxCost, minCost);
            } else {
                cout << "No patient data available." << endl;
            }
        } else if (choice == 3) {
            displayDiseaseTable();
            displayDosageTable();
        } else if (choice == 4) {
            cout << "\n========================================================================================" << endl;
            cout << "\t\tExiting the system. Thank You For Choosing us Goodbye!" << endl;
            cout << "========================================================================================" << endl;
        } else {
            cout << "Invalid choice! Please select an option between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
