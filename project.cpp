#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Resistor {
private:
    string band1, band2, multiplierBand, toleranceBand;
    double resistance, tolerance;

public:
    void input() {
        cout << "\nBand 1 Colors (Digit 1):\n";
        cout << "1. black\n2. brown\n3. red\n4. orange\n5. yellow\n";
        cout << "6. green\n7. blue\n8. violet\n9. gray\n10. white\n";
        cout << "Enter Band 1 Color: "; cin >> band1;

        cout << "\nBand 2 Colors (Digit 2):\n";
        cout << "1. black\n2. brown\n3. red\n4. orange\n5. yellow\n";
        cout << "6. green\n7. blue\n8. violet\n9. gray\n10. white\n";
        cout << "Enter Band 2 Color: "; cin >> band2;

        cout << "\nMultiplier Colors:\n";
        cout << "1. black\n2. brown\n3. red\n4. orange\n5. yellow\n";
        cout << "6. green\n7. blue\n8. gold\n9. silver\n";
        cout << "Enter 3rd Band Color (Multiplier): "; cin >> multiplierBand;

        cout << "\nTolerance Colors:\n";
        cout << "1. brown\n2. red\n3. green\n4. blue\n5. violet\n";
        cout << "6. gray\n7. gold\n8. silver\n";
        cout << "Enter 4th Band Color (Tolerance): "; cin >> toleranceBand;
    }

    void calculate() {
        int n1 = 0, n2 = 0;
        double mult = 1;

        if(band1=="black") n1=0;
		else if(band1=="brown") n1=1;
		else if(band1=="red") n1=2;
        else if(band1=="orange") n1=3;
		else if(band1=="yellow") n1=4;
		else if(band1=="green") n1=5;
        else if(band1=="blue") n1=6;
		else if(band1=="violet") n1=7;
		else if(band1=="gray") n1=8;
        else if(band1=="white") n1=9;

        if(band2=="black") n2=0;
		 else if(band2=="brown") n2=1; 
		 else if(band2=="red") n2=2;
        else if(band2=="orange") n2=3; 
		else if(band2=="yellow") n2=4; 
		else if(band2=="green") n2=5;
        else if(band2=="blue") n2=6; 
		else if(band2=="violet") n2=7;
		 else if(band2=="gray") n2=8;
        else if(band2=="white") n2=9;
        
        if(multiplierBand=="black") mult=1; 
		else if(multiplierBand=="brown") mult=10;
		else if(multiplierBand=="red") mult=100;
        else if(multiplierBand=="orange") mult=1000;
		else if(multiplierBand=="yellow") mult=10000;
        else if(multiplierBand=="green") mult=100000;
		else if(multiplierBand=="blue") mult=1000000;
        else if(multiplierBand=="gold") mult=0.1;
		else if(multiplierBand=="silver") mult=0.01;

        if(toleranceBand=="brown") tolerance=1;
		else if(toleranceBand=="red") tolerance=2; 
        else if(toleranceBand=="green") tolerance=0.5;
		else if(toleranceBand=="blue") tolerance=0.25;
        else if(toleranceBand=="violet") tolerance=0.1;
		else if(toleranceBand=="gray") tolerance=0.05;
        else if(toleranceBand=="gold") tolerance=5;
        else if(toleranceBand=="silver") tolerance=10;

        resistance = (n1*10 + n2) * mult;
    }

    void display() {
        cout << fixed << setprecision(2);
        cout << "\nResistor Value: " << resistance ;
        cout << "\nTolerance: " << tolerance << "%\n";

        ofstream outFile("resistor_result.txt");
        outFile << "Resistor Value: " << resistance  ;
        outFile << "Tolerance: " << tolerance ;
        outFile.close();
        cout << "Result saved to file also\n";
    }
};

int main() {
    Resistor r;
    cout << ".................. 4-Band Resistor Calculator..................\n";
    r.input();
    r.calculate();
    r.display();
    return 0;
}
