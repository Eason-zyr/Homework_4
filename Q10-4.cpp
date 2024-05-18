//a user subsribe list input and copy
#include<iostream>
#include<string>
using namespace std;

typedef string* sptr;                                                          //name string* as sptr

class Subscriber {                                                             //a class named Subscriber
public:
	Subscriber() :name(""), numChannels(0) { channellist = new string[0]; }    //constructors 
	Subscriber(string name, int nChs) :name(name), numChannels(nChs) { channellist = new string[nChs]; }
	Subscriber(const Subscriber& sub1);                                        //copy constructor
	void set_name(string name) { this->name = name; }                          //set functions
	void set_nChs(int num) { numChannels = num; }
	void set_list(string list[]);
	string get_name() const { return(name); }                                  //get functionsa
	int get_nChs() const { return(numChannels); }
	void get_list() const;
	void input();                                                              //let user to input
	Subscriber& operator=(const Subscriber& Sub1);                             //overloading =
	~Subscriber() { delete[] this->channellist; }                              //destructor
private:
	string name;                                                               //private variables
	int numChannels;
	sptr channellist;
};

int main(void) {
	cout << "Input subscriber's infromations..." << endl;
	Subscriber user, copy;                                 //constrotor to build two objects
	user.input();                                          //testing input
	cout << endl << "Your channel list:" << endl;
	user.get_list();                                       //testing output

	cout << endl << "The copy list is below:" << endl;
	copy = user;                                           //testing copy
	cout << "User's name: " << copy.get_name() << endl;    
	cout << "Channel list: " << endl;
	copy.get_list();

	system("pause");
	return(0);
}

void Subscriber::set_list(string list[]) {
	for (int i = 0; i < numChannels; i++) {
		channellist[i] = list[i];
	}
}

void Subscriber::get_list() const {
	for (int i = 0; i < numChannels; i++) {
		cout << i + 1 << ". " << channellist[i] << endl;
	}
}

void Subscriber::input() {
	int num;                                             //store channels number
	string user_name,chname;                             //store user's name and channel's name

	cout << "What your name ? >> ";
	cin >> user_name;
	this->set_name(user_name);
	cout << "How many channels you subscribed ? >> ";
	cin >> num;
	this->set_nChs(num);
	channellist = new string[num];                       //a dynamic array
	cout << "Input each channel's name: " << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << ". ";
		cin >> chname;
		channellist[i] = chname;
	}
}

Subscriber& Subscriber::operator=(const Subscriber& Sub1) {    //overloading = (deep copy)
	name = Sub1.name;
	
	if (numChannels != Sub1.numChannels) {                     //ensure array size is the same 
		delete[] channellist;
		channellist = new string[Sub1.numChannels];            //allocate new size
	}
	
	numChannels = Sub1.numChannels;

	for (int i = 0; i < numChannels; i++) {                    //copy each channel
		channellist[i] = Sub1.channellist[i];
	}
	return(*this);
}

Subscriber::Subscriber(const Subscriber& sub1) :name(sub1.name), numChannels(sub1.numChannels) {
	channellist = new string[numChannels];
	for (int i = 0; i < numChannels; i++) {
		channellist[i] = sub1.channellist[i];
	}
}