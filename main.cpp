#include <iostream>
#include <string>
using namespace std;

// Greeting Function
void displayGreeting() {
    cout << "\n************************************\n";
    cout << "*______   Welcome to Airline Booking System! ______  *\n";
    cout << "*     Book Your Flight in Seconds       *\n";
    cout << "************************************\n\n";
}

// About Us Function
void aboutUs() {
    cout << "\nAbout Us:\n";
    cout << "We offer a seamless airline booking experience with real-time seat selection and payment confirmation.\n";
    cout << "Choose from leading airlines, book flights, and enjoy a hassle-free reservation process!\n\n";
}

// User Class
class User {
public:
    string name, email;
    bool isLoggedIn;
//my default constructor
    User() {
    isLoggedIn=false;
    }

    void createAccount() {
        cout << "Enter Name: ";

        getline(cin, name);
        cout << "Enter Email: ";
        cin >> email;
        isLoggedIn = true;
        cout << "Account created successfully! Welcome, " << name << endl;
    }

    void signIn() {
        string inputEmail;
        cout << "Enter Email to Sign In: ";
        cin >> inputEmail;
        if (inputEmail == email) {
            isLoggedIn = true;
            cout << "Sign In successful. Welcome back, " << name << ".\n";
        } //else {
           // cout << "Error: Email not found. Please create an account.\n";
           // isLoggedIn = false;
        }
 //   }
};

// Airline Selection
void chooseAirline() {
    int choice;
    cout << "\nSelect an Airline:\n";
    cout << "1. PIA (Pakistan International Airlines)\n";
    cout << "2. AirBlue\n";
    cout << "3. Emirates\n";
    cout << "4. Qatar Airways\n";
    cout << "5. Turkish Airlines\n";
    cout << "6. British Airways\n";
    cin >> choice;

    switch (choice) {
        case 1: cout << "You selected PIA.\n";
        break;
        case 2: cout << "You selected AirBlue.\n";
         break;
        case 3: cout << "You selected Emirates.\n";
         break;
        case 4: cout << "You selected Qatar Airways.\n";
         break;
        case 5: cout << "You selected Turkish Airlines.\n";
        break;
        case 6: cout << "You selected British Airways.\n";
        break;
        default: cout << "Invalid selection.\n";
    }
}

// Country Selection
void chooseCountry() {
    int choice;
    cout << "\nSelect a Country:\n";
    cout << "1. Pakistan\n2. UAE\n3. USA\n4. UK\n5. Turkey\n6. Malaysia\n";
    cin >> choice;

    switch (choice) {
        case 1: cout << "You selected Pakistan.\n";
         break;
        case 2: cout << "You selected UAE.\n";
         break;
        case 3: cout << "You selected USA.\n";
         break;
        case 4: cout << "You selected UK.\n";
        break;
        case 5: cout << "You selected Turkey.\n";
         break;
        case 6: cout << "You selected Malaysia.\n";
        break;
        default: cout << "Invalid selection.\n";
    }
}

// City Selection
void chooseCity() {
    int choice;
    cout << "\nSelect a Destination City:\n";
    cout << "1. Karachi\n2. Lahore\n3. Islamabad\n4. Dubai\n5. London\n6. New York\n";
    cin >> choice;

    switch (choice) {
        case 1: cout << "You selected Karachi.\n";
        break;
        case 2: cout << "You selected Lahore.\n";
        break;
        case 3: cout << "You selected Islamabad.\n";
         break;
        case 4: cout << "You selected Dubai.\n";
         break;
        case 5: cout << "You selected London.\n";
        break;
        case 6: cout << "You selected New York.\n";
         break;
        default: cout << "Invalid selection.\n";
    }
}

// Payment Class
class Payment {
public:
    static bool processPayment(float amount) {
        char confirm;
        cout << "Total amount: Rs. " << amount << "\n";
        cout << "Confirm payment (Y/N): ";
        cin >> confirm;

        if (confirm == 'Y' || confirm == 'y') {
            cout << "Payment successful!\n";
            return true;
        } else {
            cout << "Payment failed. Booking canceled.\n";
            return false;
        }
    }
};

// Seat Class
class Seat {
public:
    int seatNumber;
    bool isBooked;
    string seatType;
    float fare;

    Seat() : seatNumber(0), seatType("Economy"), fare(0), isBooked(false) {}

    Seat(int num, string type, float price) : seatNumber(num), seatType(type), fare(price), isBooked(false) {}

    bool bookSeat() {
        if (!isBooked) {
            if (Payment::processPayment(fare)) {
                isBooked = true;
                cout << "Seat " << seatNumber << " (" << seatType << ") booked successfully for Rs. " << fare << ".\n";
                return true;
            }
        } else {
            cout << "Seat " << seatNumber << " is already booked.\n";
        }
        return false;
    }
    };


// Flight Class
class Flight {
public:
    string flightNumber;
    string destination;
    Seat seats[5];
//parameterized constructor
    Flight(string num, string dest) : flightNumber(num), destination(dest) {
        seats[0] = Seat(1, "Business", 50000);
        seats[1] = Seat(2, "Business", 50000);
        seats[2] = Seat(3, "Economy", 25000);
        seats[3] = Seat(4, "Economy", 25000);
        seats[4] = Seat(5, "Economy", 25000);
    }

    void displaySeats() {
        cout << "Available seats for flight " << flightNumber << ":\n";
        for (int i = 0; i < 5; i++) {
            cout << "Seat " << seats[i].seatNumber << " (" << seats[i].seatType << ") Rs. " << seats[i].fare
                 << (seats[i].isBooked ? " (Booked)" : " (Available)") << "\n";
        }
    }

    bool bookSeat(int seatNum) {
        if (seatNum > 0 && seatNum <= 5) {
            return seats[seatNum - 1].bookSeat();
        } else {
            cout << "Invalid seat number.\n";
            return false;
        }
    }


    void displaySeatSummary() {
    int totalBusiness = 0, bookedBusiness = 0;
    int totalEconomy = 0, bookedEconomy = 0;

    for (int i = 0; i < 5; i++) {
        if (seats[i].seatType == "Business") {
            totalBusiness++;
            if (seats[i].isBooked) bookedBusiness++;
        } else if (seats[i].seatType == "Economy") {
            totalEconomy++;
            if (seats[i].isBooked) bookedEconomy++;
        }
    }


    int totalSeats = totalBusiness + totalEconomy;
    int bookedTotal = bookedBusiness + bookedEconomy;

    cout << "\n--- Seat Summary ---\n";
    cout << "Total Business Seats: " << totalBusiness
         << " | Booked: " << bookedBusiness
         << " | Vacant: " << (totalBusiness - bookedBusiness) << endl;

    cout << "Total Economy Seats: " << totalEconomy
         << " | Booked: " << bookedEconomy
         << " | Vacant: " << (totalEconomy - bookedEconomy) << endl;

    cout << "Overall Total Seats: " << totalSeats
         << " | Booked: " << bookedTotal
         << " | Vacant: " << (totalSeats - bookedTotal) << endl;



}
};

class ConnectingFlight {
public:
    Flight firstLeg;
    Flight secondLeg;
    int layoverMinutes;

    ConnectingFlight(Flight leg1, Flight leg2, int layover)
        : firstLeg(leg1), secondLeg(leg2), layoverMinutes(layover) {}

    void displayConnectionDetails() {
        cout << "\n--- Connecting Flight Details ---\n";
        cout << "First Leg: " << firstLeg.flightNumber << " to " << firstLeg.destination << endl;
        cout << "Second Leg: " << secondLeg.flightNumber << " to " << secondLeg.destination << endl;
        cout << "Layover Time: " << layoverMinutes << " minutes\n";
    }

    void displayAllSeats() {
        cout << "\nSeats for First Leg:\n";
        firstLeg.displaySeats();
        cout << "\nSeats for Second Leg:\n";
        secondLeg.displaySeats();
    }

    void bookConnectingSeats(int seat1, int seat2) {
        cout << "\nBooking First Leg...\n";
        if (firstLeg.bookSeat(seat1)) {
            cout << "\nBooking Second Leg...\n";
            secondLeg.bookSeat(seat2);
        }
    }
};

// Contact Us Section
void contactUs() {
    cout << "\nContact Us:\n";
    cout << " Email: support@airline.com\n";
    cout << " Landline: +92-42-1234567\n";
    cout << " X (Twitter): @AirlineSupport\n";
}

// Ratings & Feedback
void collectFeedback() {
    int rating;
    string feedback;

    cout << "\nRate your experience (1-5): ";
    cin >> rating;
    cin.ignore();

    cout << "Leave your feedback: ";
    getline(cin, feedback);

    cout << "Thank you for your feedback! You rated " << rating << " stars.\n";
    cout << "Your comment: " << feedback << "\n";
}

// Main function
int main() {
    displayGreeting();
    aboutUs();

    User user;
    int choice;

    cout << "1. Create Account\n 2. Sign In\n";
    cin >> choice;

    if (choice == 1) {
        cin.ignore();
        user.createAccount();
    } else if (choice == 2) {
        user.signIn();
        if (!user.isLoggedIn) {
            return 0;
        }
    } else {
        cout << "Invalid option.\n";
        return 0;
    }

    chooseAirline();
    chooseCountry();
    chooseCity();
    Flight domestic1("PK301", "Lahore");
    Flight domestic2("PK302", "Karachi");
    ConnectingFlight connection(domestic1, domestic2, 75);

     connection.displayConnectionDetails();
     connection.displayAllSeats();

    int seat1, seat2;
    cout << "Select seat for first leg: ";
    cin >> seat1;
    cout << "Select seat for second leg: ";
    cin >> seat2;

    connection.bookConnectingSeats(seat1, seat2);


    Flight flight1("PK123", "Dubai");
    flight1.displaySeats();

    //int seatNum;
   // cout << "Enter seat number to book: ";
    //cin >> seatNum;

   // if (flight1.bookSeat(seatNum)) {
    flight1.displaySeatSummary();
    // Showing updated seat data after booking
    collectFeedback();

    contactUs();

    return 0;
}
