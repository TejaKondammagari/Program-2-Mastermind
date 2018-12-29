/*  mastermind.cpp
 
 Class: CS 141, Fall 2018
 Tues 9am lab
 System: Mac OS using xCode
 Author: Tejaswi Reddy Kondammagari
 
 45 points Grading Rubric for Programming Style
 
 10 Meaningful identifier names
 10 Comments: Has header.  Comments on each block of code
 10 Functional Decomposition
 10 Appropriate data and control structures
 5 Code Layout: Appropriate indentation and blank lines
 */
#include <iostream>
#include <iomanip> // to use setw
#include <cstdlib> // needed for rand() to work
#include <vector> // to use vectors
#include <string>
using namespace std;

// random number generator
vector <int> randomNumber (){
    int randomNumber1;
    vector <int> randomizedNumber; // Vector to store random number
    
    randomNumber1 = rand() % 10;
    randomizedNumber.push_back(randomNumber1); // adding first digit to vector
    
    int randomNumber2;
    randomNumber2= rand() % 10;
    if (randomNumber2==randomNumber1){ // checking for distinct values
        randomNumber2= rand () % 10;
    }
    else{
        randomizedNumber.push_back(randomNumber2); // adding second digit to vector
    }
    
    int randomNumber3;
    randomNumber3 = rand()%10;
    if ((randomNumber3==randomNumber2) || (randomNumber3==randomNumber1)){ // checking for distint values
        randomNumber3 = rand()%10;
    }
    else{
        randomizedNumber.push_back(randomNumber3); // adding third digit to vector
    }
    
    return randomizedNumber; // returns random number
}

// function to take user's number
vector <int> userChoice (){
    vector <int> userNumber; // storing user's number
    cout << "Enter three distinct digits each in the range 0..9 (e.g. 354): "<<endl;
    
    
    char firstNumber; // storing digit as a character
    char secondNumber; // storing digit as a character
    char thirdNumber; // storing digit as a character
    
    cin>>firstNumber>>secondNumber>>thirdNumber; // collects 3 numbers from user
    int numberOne = firstNumber-48; // converts character to int
    userNumber.push_back(numberOne);
    int numberTwo = secondNumber-48; // converts character to int
    userNumber.push_back(numberTwo);
    int numberThree = thirdNumber-48; // converts character to int
    userNumber.push_back(numberThree);
    
    return userNumber; // returns user's number
}

//-------------------------------------------------------------------
int main()
{
    cout << "Program: 2 MasterMind" << endl;
    cout << "The program selects 3 distinct random digits 0..9." << endl;
    cout << "On each turn you guess 3 digits. The program indicates "<< endl;
    cout << "how many are correct. You have 10 moves to guess the number."<<endl;
    cout<<" Good luck! "<< endl << endl;
    
    cout << "Press 's' to set the three digits, or 'r' to randomize them: ";
    
    vector <int> hiddenNumber; // vector to store random number or user choice
    
    cout<<endl<<endl;
    
    char input; // to store input from user
    
    cin >> input; // takes input from user
    
    // compares user's decision about random number and calls the relevant function
    if ( input == 'r' ){
        hiddenNumber = randomNumber ();
    }
    else if( input == 's' ){
        hiddenNumber = userChoice();
    }
    cout<<"Input of 000 displays the hidden digits.  Input of 999 exits the program."<<endl<<endl<<endl;
    
    // printing "in place" and "out of place" statements
    cout<<setw(36)<<"In place";
    cout<<"  ";
    cout<<"Out of place"<<endl;
    cout<<setw(36)<<"--------";
    cout<<"  ";
    cout<<"------------"<<endl;
    
    // collects the user's guess and stores as character
    char intake1;
    char intake2;
    char intake3;
    
    // stores user's guess after ASCII to number conversion
    int firstNumber;
    int secondNumber;
    int thirdNumber;
    
    int positionCounter1=0; // counts the digits out of place
    int positionCounter2=0; // counts digits in place
    
    // converting ASCII to integer
    firstNumber=intake1-48;
    secondNumber=intake2-48;
    thirdNumber=intake3-48;
    
    int i; // counter for "for loop"
    
    // loop to check user's input and validate input
    for (i=1; i<=10; i++){
        cout<<i<<". "; // displays the attempt number
        
        cout<<"Your guess: "<<endl;
        
        cin>>intake1>>intake2>>intake3; // takes input from user
        
        // converts user's input from ASCII to integer
        firstNumber=intake1-48;
        secondNumber=intake2-48;
        thirdNumber=intake3-48;
        
        // checks if user wants to exit the program
        if (firstNumber==9 && secondNumber==9 && thirdNumber==9){
            cout<<setw(18)<<"Exiting loop..."<<endl<<endl;
            cout<<setw(25)<<"Better luck next time."<<endl;
            break;
        }
        
        // checks if user wants to display the hidden number
        if (firstNumber==0 && secondNumber==0 && thirdNumber==0){
            cout<<"Hidden digits are: ";
            for (int j=0; j<3; j++){
                cout<<hiddenNumber[j];
            }
            cout<<endl;
            i-=1; // reverts the attempt number
            continue;
        }
        
        // displays the user what he entered
        cout << setw (24) << "You entered: " ;
        cout << firstNumber << secondNumber << thirdNumber ;
        
        // reverts both counters to 0
        positionCounter1 = 0 ;
        positionCounter2 = 0 ;
        
        // Tests if the first digit is in place or out of place
        if ( firstNumber == hiddenNumber.at(0) || firstNumber == hiddenNumber.at(1) || firstNumber == hiddenNumber.at(2)){
            
            if ( firstNumber == hiddenNumber.at(0)){
                positionCounter2+=1;
            }
            if (firstNumber==hiddenNumber.at(1)){
                positionCounter1+=1;
            }
            if (firstNumber==hiddenNumber.at(2)){
                positionCounter1+=1;
            }
        }
        // Tests if the second digit is in place or out of place
        if (secondNumber==hiddenNumber.at(0) || secondNumber==hiddenNumber.at(1) || secondNumber==hiddenNumber.at(2)){
            
            if (secondNumber==hiddenNumber.at(0)){
                positionCounter1+=1;
            }
            if (secondNumber==hiddenNumber.at(1)){
                positionCounter2+=1;
            }
            if (secondNumber==hiddenNumber.at(2)){
                positionCounter1+=1;
            }
        }
        
        // Tests if the third digit is in place or out of place
        if (thirdNumber==hiddenNumber.at(0) || thirdNumber==hiddenNumber.at(1) || thirdNumber==hiddenNumber.at(2)){
            
            if (thirdNumber==hiddenNumber.at(0)){
                positionCounter1+=1;
            }
            if (thirdNumber==hiddenNumber.at(1)){
                positionCounter1+=1;
            }
            if (thirdNumber==hiddenNumber.at(2)){
                positionCounter2+=1;
            }
        }
        
        cout<<setw(6)<<positionCounter2<<setw(11)<<positionCounter1<<endl; // displays number of digits in place and out of place
        
        // congratulates if user wins the game
        if (positionCounter2==3){
            cout<<endl;
            cout<<"*** Congratulations! ***"<<endl;
            break; // exits the loop
        }
    }
    
    // Checks if user lost the game and wishes him luck
    if (i==11 && positionCounter2!=3){
        cout<<"Better luck next time."<<endl<<endl;
    }
    cout<<endl;
    cout <<"Exiting program..."<< endl;
    
    return 0;
}


