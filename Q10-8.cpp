//input and customize the informations of televisions
#include <iostream>
#include <string>
using namespace std;

typedef string* sptr;                                     //string* named as sptr

class Television {                                        //a class named Television
public:                                                   //constructors
    Television() : displayType(""), dimension(0), connectivityCount(0), connectivitySupport(nullptr) {}
    Television(string type, double inch, string supt[], int count) : displayType(type), dimension(inch), connectivityCount(count) {
        set_supt(supt, count);
    }
    Television(const Television& TV);                     //copy constructor
    void set_type(string type) { displayType = type; }    //set functions
    void set_inch(double inch) { dimension = inch; }
    void set_supt(string supt[], int count);
    string get_type() const { return displayType; }       //get functions
    double get_inch() const { return dimension; }
    void get_supt() const;
    Television& operator=(const Television& TV);          //overloading =
    void customize();                                     //to modify the television
    ~Television(){ delete[] connectivitySupport; }        //destructor
private:
    string displayType;                                   //private variable
    double dimension;
    int connectivityCount;
    sptr connectivitySupport;
};

typedef Television* tvptr;                                //Television* named as tvptr

int main(void) {
    int num, amount;                                      //store ways number,televisions amount
    double inch;                                          //inches
    char ans;                                             //user's answer
    string type, way;                                     //television type,connectivity way
    sptr support;                                         //store ways

    cout << "Set your television informations..." << endl;
    cout << "What type? >> ";
    cin >> type;
    cout << "What dimensions? >> ";
    cin >> inch;
    cout << "How many connectivity ways? >> ";
    cin >> num;
    support = new string[num];
    for (int i = 0; i < num; i++) {
        cout << i + 1 << ". way >> ";
        cin >> way;
        support[i] = way;
    }
    Television TV(type, inch, support, num);              //build object by constructor

    cout << "How many television you want? >> ";
    cin >> amount;
    tvptr TV_array = new Television[amount];
    for (int i = 0; i < amount; i++) {                    //copy TV to required amount
        TV_array[i] = TV;
    }

    cout << "Do you want to customize? (Yes : Y/y, No : N/n) >> ";
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {                       //check whether user want to customize
        do {
            cout << "Which one? input number >> ";        //choose which TV
            cin >> num;
            TV_array[num - 1].customize();
            cout << "customize again? (Yes : Y/y, No : N/n) >> ";
            cin >> ans;
        } while (ans == 'Y' || ans == 'y');
    }
                                                          //output informations of each TV
    cout << endl << "Below is your all televisions:" << endl;
    for (int i = 0; i < amount; i++) {
        cout << "TV " << i + 1 << " :" << endl;
        cout << "Display Type: " << TV_array[i].get_type() << endl;
        cout << "Dimension: " << TV_array[i].get_inch() << " inches" << endl;
        cout << "Connectivity support: " << endl;
        TV_array[i].get_supt();
        cout << endl;
    }

    delete[] support;                                     //relase memomry
    delete[] TV_array;

    return 0;
}

Television::Television(const Television& TV) : displayType(TV.displayType), dimension(TV.dimension), 
connectivityCount(TV.connectivityCount) {
    connectivitySupport = new string[connectivityCount];
    for (int i = 0; i < connectivityCount; ++i) {
        connectivitySupport[i] = TV.connectivitySupport[i];
    }
}

void Television::set_supt(string supt[], int count) {
    delete[] connectivitySupport;                         //relase then create a new array (can deep copy)
    connectivityCount = count;
    connectivitySupport = new string[count];
    for (int i = 0; i < count; ++i) {
        connectivitySupport[i] = supt[i];
    }
}

void Television::get_supt() const {
    for (int i = 0; i < connectivityCount; ++i) {
        cout << i + 1 << ". " << connectivitySupport[i] << endl;
    }
}

Television& Television::operator=(const Television& TV) {
    if (this != &TV) {                                    //avoid self copy
        displayType = TV.displayType;
        dimension = TV.dimension;
        set_supt(TV.connectivitySupport, TV.connectivityCount);
    }
    return *this;
}

void Television::customize() {
    int num;                                              //store connectivity ways
    double inch;                                          //inches
    string type, way;                                     //television type,connectivity way

    cout << "What type? >> ";
    cin >> type;
    set_type(type);
    cout << "What dimensions? >> ";
    cin >> inch;
    set_inch(inch);
    cout << "How many connectivity ways? >> ";
    cin >> num;

    sptr new_support = new string[num];
    for (int i = 0; i < num; ++i) {
        cout << i + 1 << ". way >> ";
        cin >> way;
        new_support[i] = way;
    }
    set_supt(new_support, num);
    delete[] new_support;                                 //release memory
}