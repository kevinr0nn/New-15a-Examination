#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/**
 * 
 * @brief This program takes flight and booking information and
 * creates tickets.txt.
 *
 * @file tickets.cpp
 * @author Kevin Rönn
 */

/**
 * main entry point of the program.
@@ -14,9 +17,91 @@
 *            argv[1] should be a filename of the flightdata file in csv format.
 *            argv[2] should be a filename of the booking file in csv format.
 * @param[out] returns 0 on success.
*/

class Flight
{
private:
    int flightNo;
    string departure;
    string destination;
    string date;
    string time;
    int nfs;
    int bfs;
    int nbs;
    int bbs;
    int nes;
    int bes;

public:
   
    // Flight setters
    void set_flightNo(int flightNo) { this->flightNo = flightNo; }
    void set_departure(string departure) { this->departure = departure; }
    void set_destination(string destination) { this->destination = destination; }
    void set_date(string date) { this->date = date; }
    void set_time(string time) { this->time = time; }

    void set_nfs(int nfs) { this->nfs = nfs * 7; } // set number of first class seats
    void increase_bfs() { this->bfs = bfs + 1; } // increase number of booked first seats

    void set_nbs(int nbs) { this->nbs = nbs * 7; } // set number of business class seats
    void increase_bbs() { this->bbs = bbs + 1; } // increase number of booked business seats

    void set_nes(int nes) { this->nes = nes * 7; } // set number of economy class seats
    void increase_bes() { this->bes = bes + 1; } // increase number of booked economy seats

    // Getters
    int get_flightNo() { return this->flightNo; }
    string get_departure() { return this->departure; }
    string get_destination() { return this->destination; }
    string get_date() { return this->date; }
    string get_time() { return this->time; }
    int get_nfs() { return this->nfs; }
    int get_bfs() { return this->bfs; }
    int get_nbs() { return this->nbs; }
    int get_bbs() { return this->bbs; }
    int get_nes() { return this->nes; }
    int get_bes() { return this->bes; }
};

class Booking
{
private:
    int bookingNo;
    string date;
    string time;
    string departure;
    string destination;
    string seatClass;
    string fName;
    string lName;

public:
    // Booking setters
    void set_bookingNo(int bookingNo) { this->bookingNo = bookingNo; }
    void set_date(string date) { this->date = date; }
    void set_time(string time) { this->time = time; }
    void set_departure(string departure) { this->departure = departure; }
    void set_destination(string destination) { this->destination = destination; }
    void set_seatClass(string seatClass) { this->seatClass = seatClass; }
    void set_fName(string fName) { this->fName = fName; }
    void set_lName(string lName) { this->lName = lName; }

    // Getters
    int get_bookingNo() { return this->bookingNo; }
    string get_date() { return this->date; }
    string get_time() { return this->time; }
    string get_departure() { return this->departure; }
    string get_destination() { return this->destination; }
    string get_seatClass() { return this->seatClass; }
    string get_fName() { return this->fName; }
    string get_lName() { return this->lName; }
};

class FlightManager
{
private:
    list<Flight *> Flights;

public:
    void read_flights(string filename)
    {
        ifstream file(filename);
        string line;
        if (file.is_open())
        {
            while (getline(file, line))
            {
                stringstream stream(line);
                Flight *f = new Flight;
                string word;

                getline(stream, word, ',');
                f->set_flightNo(atoi(word.c_str()));
                getline(stream, word, ',');
                f->set_departure(word);
                getline(stream, word, ',');
                f->set_destination(word);
                getline(stream, word, ',');
                f->set_date(word);
                getline(stream, word, ',');
                f->set_time(word);
                getline(stream, word, ',');
                f->set_nfs(atoi(word.c_str()));
                getline(stream, word, ',');
                f->set_nbs(atoi(word.c_str()));
                getline(stream, word, ',');
                f->set_nes(atoi(word.c_str()));

                Flights.push_back(f);
            }
        }
        file.close();
    }

    void show_flights(list<Flight *> Flights)
    {
        list<Flight *>::iterator f;

        for (f = Flights.begin(); f != Flights.end(); ++f)
        {
            cout << "FlightNo: " << (*f)->get_flightNo() << endl;
        }
    }

    list<Flight *> get_flights()
    {
        return Flights;
    }
};

class BookingManager
{
private:
    list<Booking *> Bookings;

public:
    void read_bookings(string filename)
    {
        ifstream file(filename);
        string line;
        if (file.is_open())
        {
            while (getline(file, line))
            {
                stringstream stream(line);
                Booking *b = new Booking;
                string word;

                getline(stream, word, ',');
                b->set_bookingNo(atoi(word.c_str()));
                getline(stream, word, ',');
                b->set_date(word);
                getline(stream, word, ',');
                b->set_time(word);
                getline(stream, word, ',');
                b->set_departure(word);
                getline(stream, word, ',');
                b->set_destination(word);
                getline(stream, word, ',');
                b->set_seatClass(word);
                getline(stream, word, ',');
                b->set_fName(word);
                getline(stream, word, ',');
                b->set_lName(word);

                Bookings.push_back(b);
            }
        }
        file.close();
    }

    void show_bookings(list<Booking *> Bookings)
    {
        list<Booking *>::iterator b;

        for (b = Bookings.begin(); b != Bookings.end(); ++b)
        {
            cout << "BookingNo: " << (*b)->get_bookingNo() << endl;
        }
    }

    list<Booking *> get_bookings()
    {
        return Bookings;
    }
};

class TicketManager
{
public:
    list<Flight *>::iterator f;
    list<Booking *>::iterator b;

    void get_seat(list<Flight *> Flights, list<Booking *> Bookings)
    {
        for (b = Bookings.begin(); b != Bookings.end(); ++b)
        {
            for (f = Flights.begin(); f != Flights.end(); ++f)
            {
                if ((*f)->get_date() == (*b)->get_date() && (*f)->get_time() == (*b)->get_time() && (*f)->get_departure() == (*b)->get_departure() && (*f)->get_destination() == (*b)->get_destination())
                {
                    int rowNum = 0, seatNum = 0;
                    

                    if ((*b)->get_seatClass() == "first")
                    {
                        (*f)->increase_bfs();
                        seatNum = (*f)->get_bfs();
                        rowNum = seatNum / 7 + 1;
                    }
                    if ((*b)->get_seatClass() == "business")
                    {
                        (*f)->increase_bbs();
                        seatNum = (*f)->get_nfs() + (*f)->get_bbs();
                        rowNum = seatNum / 7 + 1;
                    }
                    if ((*b)->get_seatClass() == "economy")
                    {
                        (*f)->increase_bes();
                        seatNum = (*f)->get_nfs() + (*f)->get_nbs() + (*f)->get_bes();
                        rowNum = seatNum / 7 + 1;
                    }

                    char filename[20];
                    sprintf(filename, "Ticket-{%d}", (*b)->get_bookingNo());
                    ofstream outfile(filename);

                    if (outfile.is_open())
                    {
                        outfile << "BOOKING: " << (*b)->get_bookingNo() << endl;
                        outfile << "FLIGHT: " << (*f)->get_flightNo() << " DEPARTURE: " << (*f)->get_departure() << " DESTINATION: ";
                        outfile << (*f)->get_destination() << " DATE: " << (*f)->get_date() << " TIME: " << (*f)->get_time() << endl;
                        outfile << "PASSENGER: " << (*b)->get_fName() << " " << (*b)->get_lName() << endl;
                        outfile << "CLASS: " << (*b)->get_seatClass() << endl;
                        outfile << "ROW: " << rowNum << " "
                                << "SEAT: " << seatNum << endl;
                    }
                    outfile.close();
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    BookingManager beg;
    beg.read_bookings("bookings.csv");

    FlightManager run;
    run.read_flights("flights.csv");

    TicketManager ticket;
    ticket.get_seat(run.get_flights(), beg.get_bookings());
    return 0;
}

