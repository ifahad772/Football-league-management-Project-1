#include<iostream> // It is an input and output library gives us access to functions like cin and cout and enhances functionlaity of the program
#include<fstream> // Library used to handle files ( opening and closing files etc )
#include<string> // library added to use functions related to string datatype
#include<iomanip> // library added to manipulate output of the program ( input output manipulator eg setw )
#include<cstdio>// library enables us to remove or rename files ( used in delete and update function )

using namespace std; // used to avoid writing std every time for input and output

const int SIZE = 4;
const int MAX_RECORDS = 11;
int rows = 0;

// Function prototypes
void addrecord(); // add function prototype,Function declared or defined below
void viewrecord();// view function prototype,Function declared or defined below
void findplayer(); // find function prototype, Function declared or defined below
void firstmenu();// Menu function prototype,Function declared or defined below
void deleteplayer();// delete function prototype,Function declared or defined below
void updaterecord();// update  function prototype,Function declared or defined below


// Function to display the menu and handle user input

// definig add record Function
// Function to add a new record to the file
void addrecord() {
    system("cls");
    int playernumber;// declaring integer variable for player number 
    string name;// declaring string variable for name
    string clubname;// declaring string variable for clubname
    string coach;// declaring string variable for coach name
    ofstream fout; // used from the fstream library fout enables us to create/open a file
    fout.open("FootballManagement.txt", ios::app);// opens file in append mode ( permnanently stores data )
    cout << "Enter Player Number: "; // prompts user to add specified input
    cin >> playernumber;// user input
    cout << "Enter Player Name: ";// prompts user to add specified input
    cin >> name;// user input
    cout << "Enter Club Name: ";// prompts user to add specified input
    cin >> clubname;// user input
    cout << "Enter Name Of the Coach: ";// prompts user to add specified input
    cin >> coach;// user input
    cout << "Record Added Successfully!" << endl; // output to let user know record has been added
    fout << playernumber << setw(15) << name << setw(15) << clubname << setw(15) << coach << endl; // fout is used from fstream libary to store the input from user in file and setw is used to store the output in a specific way
    fout.close();// closing the file
}
// definig view record function
// Function to view all records in the file
void viewrecord() {
    system("cls");
    ifstream fin;// opens file in read mode
    fin.open("FootballManagement.txt");// file specified to be opened
    // exception handling applied in case file is not opened or not found 

    try
    {
        if (fin.fail())
        {
            throw runtime_error(" File Not Found!!!");// run time error is thrown here
        }
    }
    catch (runtime_error& e)// catches run time error / thrown value
    {
        cout << " Exceptional Handling : " << e.what() << endl; // display if error occurs
    }

    int playernumber;// declaring integer variable for player number 
    string name;// declaring string variable for name
    string clubname;// declaring string variable for clubname
    string coach;// declaring string variable for coach name 
    cout << "Number" << setw(9) << "Name" << setw(14) << "Club" << setw(16) << "Coach" << endl; // displaying output with proper spacing / indentation
    // while loop is used to read data from the file ( reads all the data from the file )
    while (fin >> playernumber >> name >> clubname >> coach) {
        cout << playernumber << setw(15) << name << setw(15) << clubname << setw(15) << coach << endl;// displays all the available and read data 
    }
    fin.close();// closing the file
}
// defining find player function 
// Function to find a player's record by player number
void findplayer() {
    system("cls");
    int playernumber;// declaring integer variable for player number 
    int numinfile; // declaring integer to check the user entered number in file
    string  name, clubname, coach; // string variables to read data from file
    cout << "Enter the Number  of Player to Find:"; // prompts user to input the player number he wants to find
    cin >> playernumber;// takes input from user / varibale stores value
    ifstream fin;// fin is used to open file in read mode
    fin.open("FootballManagement.txt");// file specified to be opened
    // exception handling applied in case file is not opened or not found 
    try
    {
        if (fin.fail())
        {
            throw runtime_error(" File Not Found!!!");// run time error is thrown here
        }
    }
    catch (runtime_error& e)// catches run time error / thrown value
    {
        cout << " Exceptional Handling : " << e.what() << endl; // display if error occurs
    }
    // while loop reads the data from the from file 
    while (fin >> numinfile >> name >> clubname >> coach) {
        // condition is applied to check the input taken from user if it matches any number stored in the file
        if (playernumber == numinfile) {
            // if condition is met function displays this output
            cout << "Match has been found! " << endl;
            cout << "Number" << setw(9) << "Name" << setw(14) << "Club" << setw(16) << "Coach" << endl;
            cout << playernumber << setw(15) << name << setw(15) << clubname << setw(15) << coach << endl;// variables output their stored values

            return;// no specified return value because void is used 
        }
    }
    // program displays this output if condition is not met
    cout << "Match not found!" << endl;
    fin.close();// closing the file
}
// defining delete player function
// Function to delete a player's record by player number
void deleteplayer() {
    system("cls");
    cout << "Enter The Number Of the Player You Want To Delete: ";
    string playernumberDelete; // string variable to take input ( after update of ide we can take int input in string ), if we take both input in int it deletes all data from file not specific
    // to take input in int we will have to then convert the input into string in order to apply a condition because data is read in string and input is in int
    // stoi will be used then ( stoi = string to integer )
    cin >> playernumberDelete;// takes user input

    ifstream fin;// opens file in read mode
    fin.open("FootballManagement.txt");// file specified to be opened
    // exception handling applied in case file is not opened or not found 
    try
    {
        if (fin.fail())
        {
            throw runtime_error(" File Not Found!!!");// run time error is thrown here
        }
    }
    catch (runtime_error& e)// catches run time error / thrown value
    {
        cout << " Exceptional Handling : " << e.what() << endl; // display if error occurs
    }
    ofstream fout("temp.txt", ios::app);// Create a temporary file for writing


    string playernumber;// declaring string variable for player number ( reason in line 157 )
    string name;// declaring string variable for name
    string clubname;// declaring string variable for clubname
    string coach;// declaring string variable for coach name

    bool recordFound = false; // bool is declared either true or false, we will be declaring it as false first
    // while loop to read data from file 
    while (fin >> playernumber >> name >> clubname >> coach) {
        // condition to check user input and read data from file to find needed data / desired output 
        // condition checks if the entered value is equal or not and condition is true or false accordingly
        if (playernumber != playernumberDelete)// if input was in int this condition would have produced an error or we would have to use stoi 
        {
            fout << playernumber << setw(15) << name << setw(15) << clubname << setw(15) << coach << endl;
        }
        // else runs if entered value is equal or found in file
        else {
            recordFound = true;
        }
    }

    fin.close();// closing main file opened in read mode
    fout.close();// closing temporary file created in write mode


    remove("FootballManagement.txt"); // enabled by cstdio library used to rename a file
    rename("temp.txt", "FootballManagement.txt");// first argument is temporary file and it will be renamed to the second argument which will be the new name of the new file
    // if bool is true program displays this output
    if (recordFound) {
        cout << "Record Deleted Successfully." << endl;
    }
    // if false then record not found
    else {
        cout << "Record not found." << endl;
    }
}
// defining update record
// Function to update a player's record by player number
// enables user to update any info of the player he wants
void updaterecord() {
    system("cls");
    cout << "Enter The Player Number To Update: ";// prompts user to input desired player number needed to update
    int playernumbertoupdate;// variabled declared to take input from user
    cin >> playernumbertoupdate; // takes input from user stores entered value

    ifstream fin;// opens file in read mode
    fin.open("FootballManagement.txt");// specified file to be opened
    try
    {
        if (fin.fail())
        {
            throw runtime_error(" File Not Found!!!");// run time error is thrown here
        }
    }
    catch (runtime_error& e)// catches run time error / thrown value
    {
        cout << " Exceptional Handling : " << e.what() << endl; // display if error occurs
    }
    ofstream fout("temp.txt");// temporary file opened in write mode , if it is opened in append mode data will not be updated

    int playernumber;// declaring integer variable for player number 
    string name;// declaring string variable for name
    string clubname;// declaring string variable for clubname
    string coach;// declaring string variable for coach name 

    bool recordFound = false;// bool is declared either true or false, we will be declaring it as false first
    // while loop is used to read data from file
    while (fin >> playernumber >> name >> clubname >> coach)
    {
        // if entered value matches value in file flag / bool is true and code runs further
        if (playernumbertoupdate == playernumber) {
            recordFound = true;
            // prompts user to enter the updated data / can enter the same data in other fields if user only wants to update specific data
            cout << "---* Enter Same Data In Field You Don't Want to update *---\n";
            cout << "Enter The Updated Number of Player : ";
            cin >> playernumber; // inputs updated player number

            cout << "Enter The Updated Name of Player: ";
            cin >> name;// inputs updated Name

            cout << "Enter The Updated Name of Club: ";
            cin >> clubname;// inputs updated club name

            cout << "Enter The Updated Name of Coach: ";
            cin >> coach;// inputs updated coach name;
        }
        // fout stores the updated data to temp file and skips the old file
        fout << playernumber << setw(15) << name << setw(15) << clubname << setw(15) << coach << endl;
    }

    fin.close();//closing file opened in read mode
    fout.close();// closing temporary opened file in write mode

    remove("FootballManagement.txt"); // enabled by cstdio library used to rename a file
    rename("temp.txt", "FootballManagement.txt");// first argument is temporary file and it will be renamed to the second argument which will be the new name of the new file
    // if condition is met and record is found and updated program displays this output
    if (recordFound) {
        cout << "Record Updated Successfully." << endl;
    }
    // program displays this output if condtion is not met bool is false
    else {
        cout << "Record not found." << endl;
    }
}

// ***** PROGRAM END *****



// Functions using array and pointers below
// each function defined whith its prototype
// add function using array and pointers
// 2d array declared in main and using global variables 
// in function array is passed with size 
void addarray_pointer(int playerinfo[][SIZE]) {
    system("cls"); // to have clear output
    if (rows < MAX_RECORDS) // condition applied so when max records are reached no more records can be added
        // size of max records can be increased by changing value in global variable
    {
        // each pointer is assigned to or points to a specific element in 2d array
        int* idptr = &playerinfo[rows][0]; // points to first index  in 2d array in rows of playerinfo array
        int* matchesplayedptr = &playerinfo[rows][1];// points to second index  in 2d array in rows of playerinfo array
        int* numofgoalsptr = &playerinfo[rows][2];// points to  third index  in 2d array in rows of playerinfo array
        int* numofassistsptr = &playerinfo[rows][3];// points to fourth index  in 2d array in rows of playerinfo array

        cout << "Enter Player ID: "; // prompts user to enter id
        cin >> *idptr;// user input which is stored in specified pointer variable
        cout << "Enter Number Of Matches Played By Player: "; // prompts user to enter num of matches
        cin >> *matchesplayedptr;// user input which is stored in specified pointer variable
        cout << "Enter Number Of Goals Scored By Player: ";// prompts user to enter goals scored
        cin >> *numofgoalsptr;// user input which is stored in specified pointer variable
        cout << "Enter Number Of Assists Provided By Player: ";// prompts user to enter assists provided
        cin >> *numofassistsptr;// user input which is stored in specified pointer variable

        cout << "RECORD ADDED SUCCESSFULLY!" << endl; // successfull record addition message
        rows++;// after record is added to first index it is incremented to next row for new record
    }
    else {
        cout<<"Maximum Amount of Records Reached!"<<endl; // condition is  not fulfilled so this message is displayed
    }
}

// view function using array and pointers
// 2d array declared in main and using global variables 
// in function array is passed with size 

void viewarray_pointer( int playerinfo[][SIZE]) {
    int row = 0;//initialized to zero because it is used as an index to access elements in array
    system("cls"); // to have clear output
    cout << "ID" << "\t" << setw(10) << "Matches" << "\t" << setw(10) << "Goals" << "\t" << setw(10) << "Assists" << endl; // manipulated output for better display

    for (int i = 0; i < MAX_RECORDS; i++)  // loop runs through each iteration and row is used to index the array accessing the records
    {
        // after loop runs and all data availabe is read its displayed using calling array and row and then each index to be displayed
        cout << playerinfo[row][0] << "\t" << setw(10) << playerinfo[row][1] << "\t" << setw(10) << playerinfo[row][2] << "\t" << setw(10) << playerinfo[row][3] << endl;
        row++; // after displaying info of the current row it is incremented to next row
    }
}

// find function using array and pointers
// 2d array declared in main and using global variables 
// in function array is passed with size 

void findarray_pointer(int playerinfo[][SIZE]) 
{
    system("cls"); // to have clear output
    int idtofind;// initalized new variable to store input by user to find the record he wants to find
    cout << "Enter ID of Player To Find: "; // prompts user to enter the id to find
    cin >> idtofind;// stores user input

    for (int i = 0; i < MAX_RECORDS; i++) // loop runs and check one record on each iteration until all indexes are checked
    {
        if (playerinfo[i][0] == idtofind)// condition applied to check if user input id matches any id in records which were read through loop
        {
            cout << "MATCH FOUND!" << endl; // condition satisfied output displayed

            // each pointer is assigned to or points to a specific element in 2d array
            int* idptr = &playerinfo[i][0]; // points to first index  in 2d array in  playerinfo array
            int* matchesplayedptr = &playerinfo[i][1];// points to second index  in 2d array  playerinfo array
            int* numofgoalsptr = &playerinfo[i][2];// points to  third index  in 2d array in  playerinfo  array
            int* numofassistsptr = &playerinfo[i][3];// points to fourth index  in 2d array in  playerinfo array

            cout << "ID" << "\t" << setw(13) << "Matches" << "\t" << setw(10) << "Goals" << "\t" << setw(11) << "Assists" << endl; // manipulated output for better display
            // displayed info for specific record and only pointer variables are used to point to specific record and not called array with indexes beacuse not required
            cout << *idptr << "\t" << setw(10) << *matchesplayedptr << "\t" << setw(10) << *numofgoalsptr << "\t" << setw(10) << *numofassistsptr << endl;
            return; 
        }
    }


    cout << "MATCH NOT FOUND!" << endl;// message displayed if record does not exist and condition is not satisfied
}
// update function using array and pointers
// 2d array declared in main and using global variables 
// in function array is passed with size 
void updatearray_pointer(int playerinfo[][SIZE]) {
    system("cls"); // to have clear output
    int idtoupdate; // initialized new variable to store input by the user to update the record he wants to update
    cout << "Enter ID To Update: ";// prompts the user to enter the id to find
    cin >> idtoupdate;// stores user input

    bool recordsfound = false; // bool first declared as false and will be called true if the condition is met
    int i = 0;  // i decalred outside loop beacuse for addinf furhter conditions after loop match found message couldn't be displayed properly 
    // match found was in between heading and data or shown after data was added

    // Display headings before the loop
    cout << "ID\tGoals\tMatches\tAssists\n";

    for (; i < MAX_RECORDS; i++) // loops run and each iteration reads a record until all records are read
    {
        if (idtoupdate == playerinfo[i][0]) // if user input matches an id in record bool will be true and code below will execute
        {
            recordsfound = true; // bool is true

            for (int j = 0; j < SIZE; j++) // loop to read columns and data in it ( columns of the row which was supposed to be updated )
            {
                cout << playerinfo[i][j] << "\t";// display current values of the player's record
            }
            cout << endl;

            break;// exit loop since the record has been found and updated
        }
    }

    if (recordsfound) {
        cout << "MATCH FOUND!"<<endl;
          cout<<"Enter Updated Information!" << endl; // message to display when the condition is met
        cout << "---* Enter Same Data In Field You Don't Want to update *---\n"; // Inform the user about updating fields

        // Rest of your code for updating the data...
        int* id = &playerinfo[i][0];// points to the first index in the 2D array in the playerinfo array
        int* matchesplayed = &playerinfo[i][1];// points to the second index in the 2D array in the playerinfo array
        int* numofgoals = &playerinfo[i][2];// points to the third index in the 2D array in the playerinfo array
        int* numofassists = &playerinfo[i][3];// points to the fourth index in the 2D array in the playerinfo array

        cout << "Enter Player ID: ";
        cin >> *id; // Update the player's ID using the pointer
        cout << "Enter Number Of Matches Played By Player: ";
        cin >> *matchesplayed; // Update the number of matches played using the pointer
        cout << "Enter Number Of Goals Scored By Player: ";
        cin >> *numofgoals; // Update the number of goals scored using the pointer
        cout << "Enter Number Of Assists Provided By Player: ";
        cin >> *numofassists; // Update the number of assists using the pointer
    }
    else {
        cout << "RECORD NOT FOUND!" << endl;// display message
    }
}


void firstmenu() {
    system("cls");// to have clear output
    // void is used to call function so there will be no specific return written
    cout << "                     ----*----                     " << endl; // added to make output presentable
    cout << "*--------FOOTBALL LEAGUE MANAGEMENT SYSTEM---------*\n";// Displaying Name of Management Program 
    cout << "*---Choose One Of The Following Actions To Perform!---*" << endl; // Giving user choice to choose his desired operation
    cout << "1. Add Record\n2. View Record\n3. Find Player\n4. Delete Player Record\n5. Update Record\n6. Exit" << endl; // operations which are performable are listed
    int option;// integer variable declared to take input from user 
    cin >> option;// value assigned to integer by user
    // switch is used to call corresponding function based on user input
    switch (option) {
    case 1: // calls add record function
        cout << " Add Record!\n";
        addrecord();
        break; // switch runs again
    case 2:// calls view record function
        cout << "View Records!\n";
        viewrecord();
        break;// switch runs again
    case 3: // calls find player function
        cout << " Find Player!\n";
        findplayer();
        break;// switch runs again
    case 4:// calls delete player function
        cout << "Delete Player Record!\n";
        deleteplayer();
        break;// switch runs again
    case 5:// calls update record function
        cout << "Update Record!\n";
        updaterecord();
        break;// switch runs again
    case 6:// program exits/ends
        cout << "Program Ends";
        exit(0);
    default:// input other than provided choices will show this default message
        cout << "Invalid Option\n";
    }
}

void secondmenu(int playerinfo[][SIZE]) {
    system("cls");// to have clear output
    // void is used to call function so there will be no specific return written
    cout << "                     ----*----                     " << endl; // added to make output presentable
    cout << "*--------FOOTBALL LEAGUE MANAGEMENT SYSTEM---------*\n";// Displaying Name of Management Program 
    cout << "*---Choose One Of The Following Actions To Perform!---*" << endl; // Giving user choice to choose his desired operation
    cout << "1. Add Record\n2. View Record\n3. Find Player\n4. Update Record\n5. Exit" << endl;// operations which are performable are listed
    int option;// integer variable declared to take input from user 
    cin >> option;// value assigned to integer by user
    // switch is used to call corresponding function based on user input
    switch (option) {

    case 1:// calls add record function
        cout << " Add Record!\n";
        addarray_pointer(playerinfo);// function called with passed array
        break;// switch runs again
    case 2:// calls view function
        cout << "View Records!\n";
        viewarray_pointer(playerinfo);// function called with passed array
        break;// switch runs again
    case 3:// calling find player function
        cout << " Find Player!\n";
        findarray_pointer(playerinfo);// function called with passed array
        break;// switch runs again
    case 4:// calling update record function
        cout << "Update Record!\n";
        updatearray_pointer(playerinfo);// function called with passed array
        break;// switch runs again
    case 5:// ends program in this case
        cout << "Program Ends";
        exit(0);// program exits
    default:// invalid value entered
        cout << "Invalid Option\n";// error message
    }
}
// another menu function defined to call the other two menus
void mainmenu(int playerinfo[][SIZE]) {
    system("cls");// to have clear output

    while (true) // runs loops until exit is initiated
    {
        cout << "                     ----*----                     " << endl;// decorative line
        cout << "*--------FOOTBALL LEAGUE MANAGEMENT SYSTEM---------*\n";// program title
        cout << "*------------------MAIN MENU-----------------------*\n";// menu title
        cout << "1. MENU 1 ( Using File Handling )\n2. MENU 2 ( Using Arrays & Pointers )\n3. EXIT\n";// options availabe to use
        int mainmenuoption;// variable to take input / choice
        cin >> mainmenuoption;// stores input

        switch (mainmenuoption)// switch used to take choice input
        {
        case 1:// calls first menu
            firstmenu();// first menu called
            break;// switch runs again
        case 2:// calls second menu
            secondmenu(playerinfo);// second menu called
            break;// switch runs again
        case 3:// initiates exit
            exit(0);// exits program
        default:// invalid value entered
            cout << "Invalid Option!" << endl;// error message displayed
        }


    }
}
// main body of program
int main()
{
    // array is declared here and values passed in array are defined globally / are global variables
    int playerinfo[MAX_RECORDS][SIZE];
    // nested loops used to read all the indexes in 2d array and initialize all the indexes of matrix zero
    for (int i = 0; i < MAX_RECORDS; i++)// runs for no of rows
    {
        for (int j = 0; j < SIZE; j++)// runs for no of columns
        {
            playerinfo[i][j] = 0;// initializes all indexes zero
        }
    }
    // infinite loop for main menu until exited
    while (true) {
        mainmenu(playerinfo);// main menu function called with declared array passed
    }
    return 0;
}