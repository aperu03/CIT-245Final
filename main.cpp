// Arianna Perugini CIT-245
// Final Project
// COVID 19 Risk Questionnaire

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// declare vector with empty elements
vector<string> nameList;
vector<int> totalList{};
vector<int> sympList{};

// method that asks the patient questions, and will then use the
// recorded data to calculate the risk of the patient, and then
// will be used to output a list of results
void getTeamInfo(){
  // initializes strings used to take in data
  string visited = "";
  string contact = "";
  string risk = "";
  string symptom = "";
  string name = "";
  
  // initializes ints that count up symptoms & total
  // amount of risks checked off per patient
  int sympCount = 0;
  int queCount = 0;
  int total = 0;

  // string input used to validate new loops per patient
  // specifically works with 'N' or 'Y' inputs only
  string input = "";

  // while loop - used to preform entire questionnaire, then asks for
  // a new input when finished
  while(input != "N"){

    // total resets to 0 each time so the amount counts up properly
    total = 0;

    // beginning of program output
    cout << "\nWelcome to Our COVID-19 Questionnaire. Please answer the following questions based on how you are feeling on a span of 12-14 days." << '\n';

    // program first asks the patient about their areas visited
    cout << "\nHave you visited an area that has high community transmission of COVID-19?" << '\n' << "Answer with 'yes' or 'no'." << '\n';
    // patient/ nurse types input
    cin >> visited;
    // following if statement adds count if question was answered 'yes'
    if (visited == "yes") {
      queCount = queCount + 1;
    }

    // program then asks about the patients recent contact  
    cout << "\nDid you have close contact with a diagnosed COVID-19 patient?" << '\n' << "Answer with 'yes' or 'no'." << '\n';
    // input typed, then is stored in contact
    cin >> contact;
    // if statement will add to the count if input was 'yes'
    if (contact == "yes") {
      queCount = queCount + 1;
    }

    // program prompts patient on their health history
    cout << "\nBased on your health history, are you at a higher risk for COVID-19?" << '\n' << "Answer with 'yes' or 'no'." << '\n';
    // input is stored in risk
    cin >> risk;
    // adds to count if input is 'yes'
    if (risk == "yes") {
      queCount = queCount + 1;
    }

    // program asks patient about their current symptoms
    cout << "\nHave you had any of the following symptoms in the past 14 days?" << '\n' << "Fever" << '\n' << "Cough" << '\n' << "Shortness of breath" << '\n' << "Chills" << '\n' << "Repeated shaking with chills" << '\n' << "Muscle pain" << '\n' << "Headache" << '\n' << "Sore throat" << '\n' << "New loss of taste or smell" << '\n' << "Gastrointestinal symptoms" << '\n' << "Answer with 'yes' or 'no'." << '\n';
    // input is placed into symptom 
    cin >> symptom;
    // if input was 'yes', program will ask for amount of symptoms patient has
    if (symptom == "yes") {
      cout << "\nYou input 'yes' for the previous question. How many symptoms have you experienced from this list? Enter a numeric value:" << '\n';
      // numeric value of symptoms is stored in sympCount
      cin >> sympCount;
      // symptom value is kept for output, so it is stored in the sympList vector
      sympList.push_back(sympCount);
    }

    // total amount of yeses & symptoms checked off are combined together
    // this is to figure out how high the patient's risk for COVID 19 is
    total = sympCount + queCount;
    totalList.push_back(total);

    // program then asks for patient's name
    cout << "\nFinally, please input your name for our records:" << '\n';
    // name input is stored in name
    cin >> name;
    // name is kept for output list, so it will be stored in the nameList vector
    nameList.push_back(name);

    // program prompts for loop/ new patient
    cout << "\nThank you for your information. Press 'Y' for another entry, or press 'N' for review." << '\n';
    cin >> input;
  }

}

// method used for outputting the results for the patients entered
void displayTeamList(){

  // title of list
  cout << "\n\nCurrent List of Patient Risks:" << '\n';

  // list of patients and their info will output here, a for loop is used
  // to list each patient by the amount of loops done
  for(int i = 0;i<nameList.size(); i=i+1){
    cout << "Patient " << i + 1 << ": " << nameList[i] << " currently has " << sympList[i] << " symptom(s). At this time, " << nameList[i] << "'s current COVID-19 risk is " << totalList[i] << "/13." << '\n';
  }

}

// main method, calls previous methods to initialize program
int main(){
  getTeamInfo();
  displayTeamList();
}