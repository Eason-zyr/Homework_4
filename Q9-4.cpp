//turn four-letter word in a sentence into love or Love
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string convert(string word);                                    //function to convert the word

int main(void) {
	char again;                                                 //to store user's answer
	do {
		int start = 0;                                          //begin with the first letter
		string sentence, converted_sentence = "", word = "";    //store begore and after sentence and word 
		cout << "Input a sentence >> ";
		getline(cin, sentence);                                 //read user's input

		for (int i = 0; i < sentence.size(); i++) {             //change to word then change to love or Love
			if (ispunct(sentence.at(i)) || sentence.at(i) == ' ' || i == sentence.size() - 1) {
				for (int j = start; j < i; j++) {
					word += sentence.at(j);
				}
				converted_sentence += convert(word);            //combine wrod after changed
				converted_sentence += sentence.at(i);
				start = i + 1;                                  //start with next word
				word = "";
			}
		}                                                       //output the result
		cout << "After converted,the sentence is : " << converted_sentence << endl;

		cout << "Continued (Y/y) or quit (N/n) >> ";            //check whether user want to continue
		cin >> again;
		cin.ignore();                                           //clean buffer
		cout << endl;
	} while (again == 'y' || again == 'Y');

	system("pause");
	return(0);
}

string convert(string word) {
	if (word.size() == 4) {                                     //if wrod is four-letter
		if (word.at(0)>='A'&& word.at(0) <= 'Z') {              //fisrt letter is capital change to Love
			return("Love");
		}
		else {
			return("love");                                     //change to love
		}
	}
	else {
		return(word);                                           //not four letter doesn't need to change
	}
}