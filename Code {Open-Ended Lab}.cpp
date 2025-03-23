#include <iostream>
#include <iomanip> 
#include <vector>  
using namespace std;

const int TOTAL_SEATS = 30; 
const double PENALTY_RATE = 0.05; 
const double HAJJ_DISCOUNT = 0.05; 
const double GROUP_DISCOUNT = 0.05; 
bool seats[TOTAL_SEATS] = {false}; 


const double BUSINESS_PRICE = 40000.0;
const double ECONOMY_PRICE = 50000.0;


struct Booking {
    int seatNumber;
    string className;
    double price;
    string destination;
    string flightTime;
};

vector<Booking> bookings; 

void displayGreetings() {
    cout << " 				 ============================================\n";
    cout << " 				  Welcome to PakWings Bookings!\n";
    cout << "  			   	 ============================================\n";
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << " 1. View Available Seats\n";
    cout << " 2. Book Seats\n";
    cout << " 3. Cancel Seats\n";
    cout << " 4. Generate Invoice\n";
    cout << " 5. Exit\n";
    cout << "Enter your choice: ";
}

void viewAvailableSeats() {
    cout << "\nAvailable Seats:\n";
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (!seats[i]) {
            cout << "Seat " << i + 1 << " is available."<<endl;
        }
    }
}

string selectDestination() {
    int choice;
    cout << "\nSelect your destination:\n";
    cout << "1. Saudi Arabia (Flight Time: 4 hours)\n";
    cout << "2. UAE (Flight Time: 3 hours)\n";
    cout << "3. Turkey (Flight Time: 6 hours)\n";
    cout << "4. UK (Flight Time: 8 hours)\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch (choice) {
        case 1: return "Saudi Arabia (4 hours)";
        case 2: return "UAE (3 hours)";
        case 3: return "Turkey (6 hours)";
        case 4: return "UK (8 hours)";
        default: return "Invalid Destination";
    }
}

void bookSeats() {
    int numSeats, seatNumber;
    char classChoice, hajjChoice;
    double totalPrice = 0.0;
    string destination, flightTime;

    cout << "\nEnter your name: ";
    string name;
    cin.ignore(); 
    getline(cin, name);

    destination = selectDestination();
    if (destination == "Invalid Destination") {
        cout << "Invalid destination selected. Please try again.\n";
        return;
    }

    
    bool isHajjPackage = false;
    if (destination.find("Saudi Arabia") != string::npos) {
        cout << "Note: \n 5 % discount for Hajj Package \nAre you booking for Hajj Package? (Y/N): 	";
        cin >> hajjChoice;
        if (hajjChoice == 'Y' || hajjChoice == 'y') {
            isHajjPackage = true;
            cout << "You are eligible for an additional 5% discount on Hajj Package!\n";
        }
    }

    cout << "\nEnter the number of seats you want to book (or enter 0 to exit): ";
    cin >> numSeats;

    if (numSeats == 0) {
        cout << "Booking process canceled.\n";
        return;
    }

    if (numSeats < 0 || numSeats > TOTAL_SEATS) {
        cout << "Invalid number of seats! Please try again.\n";
        return;
    }

    
    bool isGroupDiscount = (numSeats > 5);

    cout << " Choose class:\n";
    cout << " B. Business Class (Rs. 40,000 per seat)\n";
    cout << " E. Economy Class (Rs. 50,000 per seat)\n";
    cout << " Enter your choice (B/E): ";
    cin >> classChoice;

    string className = (classChoice == 'B' || classChoice == 'b') ? "Business Class" : "Economy Class";
    double pricePerSeat = (classChoice == 'B' || classChoice == 'b') ? BUSINESS_PRICE : ECONOMY_PRICE;

    for (int i = 0; i < numSeats; i++) {
        viewAvailableSeats();
        cout << "Enter seat number for seat " << i + 1 << " (or enter 0 to exit): ";
        cin >> seatNumber;

        if (seatNumber == 0) {
            cout << "Booking process canceled.\n";
            return;
        }

        if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
            cout << "Invalid seat number! Please try again.\n";
            i--; 
            continue;
        }

        if (seats[seatNumber - 1]) {
            cout << "Seat " << seatNumber << " is already booked. Please choose another seat.\n";
            i--; 
        } else {
            seats[seatNumber - 1] = true; 
            double finalPrice = pricePerSeat;

            
            if (isHajjPackage) {
                finalPrice -= finalPrice * HAJJ_DISCOUNT;
            }

            totalPrice += finalPrice;
            bookings.push_back({seatNumber, className, finalPrice, destination, flightTime}); 
            cout << "Seat " << seatNumber << " has been successfully booked!\n";
        }
    }

    
    if (isGroupDiscount) {
        double discountAmount = totalPrice * GROUP_DISCOUNT;
        totalPrice -= discountAmount;
        cout << "\nYou have booked more than 5 seats. A 5% discount has been applied!\n";
        cout << "Discount Amount: Rs. " << fixed << setprecision(2) << discountAmount << "\n";
    }

    cout << "\nTotal Price: Rs. " << fixed << setprecision(2) << totalPrice << "\n";
}

void cancelSeats() {
    int numSeats, seatNumber;
    double totalRefund = 0.0;

    cout << "\nEnter the number of seats you want to cancel (or enter 0 to exit): ";
    cin >> numSeats;

    if (numSeats == 0) {
        cout << "Cancellation process canceled.\n";
        return;
    }

    if (numSeats < 0 || numSeats > TOTAL_SEATS) {
        cout << "Invalid number of seats! Please try again.\n";
        return;
    }

    for (int i = 0; i < numSeats; i++) {
        cout << "Enter seat number for cancellation " << i + 1 << " (or enter 0 to exit): ";
        cin >> seatNumber;

        if (seatNumber == 0) {
            cout << "Cancellation process canceled.\n";
            return;
        }

        if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
            cout << "Invalid seat number! Please try again.\n";
            i--; 
            continue;
        }

        if (!seats[seatNumber - 1]) {
            cout << "Seat " << seatNumber << " is not booked. Nothing to cancel.\n";
            i--; 
        } else {
            seats[seatNumber - 1] = false; 
            double refundAmount = (seatNumber <= 15) ? BUSINESS_PRICE : ECONOMY_PRICE; 
            refundAmount -= refundAmount * PENALTY_RATE; 
            totalRefund += refundAmount;

            
            for (auto it = bookings.begin(); it != bookings.end(); ++it) {
                if (it->seatNumber == seatNumber) {
                    bookings.erase(it);
                    break;
                }
            }

            cout << "Seat " << seatNumber << " has been successfully canceled.\n";
            cout << "Refund after 5% penalty: Rs. " << fixed << setprecision(2) << refundAmount << "\n";
        }
    }

    cout << "\nTotal Refund: Rs. " << fixed << setprecision(2) << totalRefund << "\n";
}

void generateInvoice() {
    if (bookings.empty()) {
        cout << "\nNo bookings found. Please book seats first.\n";
        return;
    }

    cout << "\n========== INVOICE ==========\n";
    cout << "Seat No.\tClass\t\tPrice\t\tDestination\t\tFlight Time\n";
    cout << "-----------------------------------------------------------------\n";

    double totalAmount = 0.0;
    for (const auto& booking : bookings) {
        cout << booking.seatNumber << "\t\t" << booking.className << "\tRs. " << fixed << setprecision(2) << booking.price << "\t\t" << booking.destination << "\t\t" << booking.flightTime << "\n";
        totalAmount += booking.price;
    }

    
    if (bookings.size() > 5) {
        double discountAmount = totalAmount * GROUP_DISCOUNT;
        totalAmount -= discountAmount;
        cout << "-----------------------------------------------------------------\n";
        cout << "Group Discount (5%): Rs. " << fixed << setprecision(2) << discountAmount << "\n";
    }

    cout << "-----------------------------------------------------------------\n";
    cout << "Total Amount: Rs. " << fixed << setprecision(2) << totalAmount << "\n";
    cout << "=================================\n";
}

int main() {
    displayGreetings();
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                viewAvailableSeats();
                break;
            case 2:
                bookSeats();
                break;
            case 3:
                cancelSeats();
                break;
            case 4:
                generateInvoice();
                break;
            case 5:
                cout << "Thank you for using the Airline Booking System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}