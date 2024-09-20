# ASSIGNMENT 1 
## "Conversion"

### Rationale:

HTML files use tags enclosed in angle brackets to denote formatting instructions. For example, '< B >' indicates
bold and '< I >' indicates italics. If a web browser is displaying an HTML document that contains < or >, it may
mistake these symbols for tags. This is a common problem with C++ files, which contain many <’s and >’s. For
example, the line “#include <iostream>” may result in the browser interpreting <iostream> as a tag. To avoid
this problem, HTML uses special symbols to denote < and >. The < symbol is created with the string &lt; while
the > symbol is created with the string &gt;.


### **Assignment**

#### Write a program that:

1) Implements file name & path validation on either the input file (.cpp) or output file (.html)
2) Reads in a C++ source file (.cpp)
3) Converts all < symbols to &lt and all > symbols to &gt.
4) Inserts the '< PRE >' and '< /PRE >' tags to the front and end of the html file respectively.
5) Outputs the modified file as an html file. 

The output file can be testing by opening it with a web browser. The contents should appear identical to 
the original source code. When you "view source" you should see the html code that includes the tag modifications. 

### **Other Criteria/Notes**
• Validation must ensure that only valid Windows file names may be procesed even if the demonstration will take 
place on a mac. This will require that you research the criteria (e.g. max length) for a valid Windows file name for 
your validation routine. 
• Validation will ensure that only valid path information us used and ask the user again if pathing for either the 
source(.cpp) or target (.html) file path is incorrect or the file not available. E.g. c:\bobFile.cpp
• The provided rubric is also considered part of this specification. Please review it as such. 

