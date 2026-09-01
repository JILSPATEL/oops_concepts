/*
Concept Explained: Multiple Inheritance + Diamond Problem + Virtual Inheritance

This program shows a classic OOP problem called the diamond problem, which occurs when a class inherits from two classes that share a common base class.

1. Base class: Device
   - It contains the common property powerStatus.

2. Derived classes: Printer and Scanner
   - Both inherit virtually from Device.
   - Virtual inheritance ensures that the common base class is included only once in the final hierarchy.

3. Final class: Copier
   - Copier inherits from both Printer and Scanner.
   - This creates a diamond-like inheritance structure, where both Printer and Scanner share a common ancestor.

4. Why virtual inheritance is needed
   - Without virtual inheritance, the Device base class may be duplicated in the Copier object, leading to ambiguity and conflict.
   - Virtual inheritance ensures a single shared instance of Device.

5. Ambiguity resolution
   - Both Printer and Scanner define processDocument(), so Copier cannot call it directly without specifying which version.
   - This is why the example uses Scanner::processDocument() and Printer::processDocument().

6. Real-world idea
   - This pattern appears in systems where multiple interfaces or features share common behavior but must be combined without duplicate data.

Example:
                 A
                / \
               /   \
              B     C
               \   /
                \ /
                 D
*/

#include <bits/stdc++.h>
using namespace std;

class Device{
    protected:
        string powerStatus;    
    public:
        Device(string status):powerStatus(status){
            cout<<"[Constructing Device] Power Status set to "<<powerStatus<<endl;
        }    
        virtual ~Device(){
            cout<<"Destruct Device"<<endl;
        }
};

class Printer: virtual public Device{
    protected: 
        string printQuality;
    public:
        Printer(string status,string quality): Device(status),printQuality(quality){
            cout<<"[Constructing Printer] Print Quality set to "<<printQuality<<endl;
        }
        void processDocument(){
            cout<<"Processing document with "<<printQuality<<" quality."<<endl;
        }
        virtual ~Printer(){
            cout<<"Destruct Printer"<<endl;
        }
};

class Scanner: virtual public Device{
    protected:
        string scanResolution;
    public:
        Scanner(string status,string resolution): Device(status),scanResolution(resolution){
            cout<<"[Constructing Scanner] Scan Resolution set to "<<scanResolution<<endl;
        }
        void processDocument(){
            cout<<"Scanning document at "<<scanResolution<<" resolution."<<endl;
        }
        virtual ~Scanner(){
            cout<<"Destruct Scanner"<<endl;
        }
};

class Copier: public Printer, public Scanner{
    public:
        Copier(string status,string quality,string resolution): Device(status),Printer(status,quality),Scanner(status,resolution){
            cout<<"[Constructing Copier] Copier is ready to use."<<endl;
        }
        void copyDocument(){
            cout<<"Copying document with "<<printQuality<<" quality and "<<scanResolution<<" resolution."<<endl;
        }
        virtual ~Copier(){
            cout<<"Destruct Copier"<<endl;
        }
};

int main(){
    Copier myCopies("ON","high","300dpi");
    //myCopies.processDocument(); // Ambiguity resolved by calling Copier's method
    myCopies.Scanner::processDocument();
    myCopies.Printer::processDocument();
    myCopies.copyDocument();    
    return 0;
}
