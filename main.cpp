#include <iostream>
#include <string>
#include <fstream>


// TODO: - research criteria for valid Windows filename (running on mac is requirement)

//           <<PSEUDOCODE>>

// step 1: Implement file name & path validation--
// check if given file path is valid. if not, it
// return false; otherwise, it returns true

    //FUNCTION isValidPath(filePath)
        //if filepath is not valid
            //return false
        //ENDIF
        //RETURN true
    //end function

// STEP 2: Read in a C++ source file --
// validate the path. if valid, open
// file and read contents into variable
// 'sourceCode' then close.

    //FUNCTION readFile(filepath)
        //IF isvalidpath(filepath) is false
            //PRINT invalid path
            //RETURN
        //ENDIF
        //OPEN file at filepath FOR reading
        //READ file content into sourceCode
        //CLOSE file
        //RETURN sourcecode
    //ENDFUNCTION

// step 3: Convert < and > symbols
    //FUNCTION convertSymbols(sourceCode)
        //REPLACE all '<' in sourceCode WITH '&lt;'
        //REPLACE all '>' in sourceCode WITH '&gt;'
        //RETURN sourceCode
    //END FUNCTION

// step 4: Insert <PRE> and </PRE> tags
    //FUNCTION addPreTags(sourceCode)
        //RETURN "<PRE>" + sourceCode + "</PRE>"
    //ENDFUNCTION

// step 5: output the modded file as HTML file
    //FUNCTION writeFile(filePath, content)
        //IF isValidPath(filePath) is false
            //PRINT invalid
            //RETURN
        //ENDIF
        //OPEN file at filepath FOR writing
        //WRITE content to file
        //CLOSE file
    //END function

    //Main program
    //INPUT inputfilepath
    //INPUT outputfilepath

    //sourceCode = readFile(inputFilePath)
    //IF sourceCode is not empty
        //modifiedCode = convertSymbols(sourceCode)
        //htmlContent = addPreTags(modifiedCode)
        //writeFile(outputFilePath, htmlContent)
        //PRINT "File conversion successful."
    //ELSE
        //PRINT failed to read
    //ENDIF
//END


using namespace std;

void openCloseStreams();
void openPrint();
void openWrite();


int main() {
    cout << "Begin fileIO Demonstration"<<endl;

    cout << "Begin Open Write Demo"<<endl;
    openWrite();
    openPrint();
    cout << "End fileIO Demonstration"<<endl;
    openCloseStreams();


    return 0;

}//end main

void openCloseStreams() {
    cout << "Files Open" << endl;

//declare stream objects
    ifstream inStream;
    ofstream outStream;

//connect files to stream objects
    inStream.open("infile.txt");
    outStream.open("outfile.txt");

//a shorter version of above
    ifstream inStream2("infile.txt");

//close resources
    inStream.close();
    outStream.close();
    inStream2.close();

    cout<<"Files closed"<<endl;
}

void openPrint(){
    string line;
    ifstream myFileIn;
//you may use either .fail() or the .is_open() method
//of the file stream object
    myFileIn.open("myFileIn.txt");
    if(myFileIn.is_open())//or if(myFileIn.fail
    {
        cout << "File Open" << endl;
        while(!myFileIn.eof()){
            getline(myFileIn,line);
            cout << line<<endl;
        }
        myFileIn.close();
        cout<<"File closed"<<endl;
    }else{
        cout << "Input file failed to open"<< endl;
    }
}//end method

void openWrite(){
    ofstream myFileOut;
//to append to a file - use ios::app
    myFileOut.open("myFileOut.txt",ios::app);//open for append
    if(!myFileOut.fail())//true if it does not fail
    {
        myFileOut << "stuff" << " and more stuff" << endl;
        myFileOut.close();
        cout << "File Closed"<< endl;
    }else{
        cout << "Output File failed to open" << endl;
    }

}
