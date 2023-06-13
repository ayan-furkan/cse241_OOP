#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


class Image{

    public:

        //CONSTRUCTORS
        Image();
        Image(string filename);

        //GETTERS
        string getFormat() const;
        int getColumn() const;
        int getRow() const;
        int getMaxColor() const;
        vector<int> getRed() const;
        vector<int> getGreen() const;
        vector<int> getBlue() const;
        
        //SETTERS
        void setFormat(string f);
        void setColumn(int c);
        void setRow(int r);
        void setMaxColor(int max);
        void setRed(vector<int> r);
        void setGreen(vector<int> g);
        void setBlue(vector<int> b);


        void downloadImage(string filename); // modify the object from given ppm file
        void uploadImage(string filename) const; // upload the object to given file name
        void convertImage(double c_r, double c_g, double c_b); // Enter 3 coefficents and modify the RGB variables

        void printDialogMenu() const; //Dialog menu include all the private member that object has


    private:
        string format; // "P3"
        int column , row , maxColor;
        vector<int> red; 
        vector<int> green;
        vector<int> blue;

};

void mainMenu();
void openImageMenu(Image& img); 
void saveImageMenu(Image& img);
void scriptMenu(Image& img);
void convertMenu(Image& img);


Image::Image(){
    //Default constructor

    vector<int> r; //Empty vector
    vector<int> g; //Empty vector
    vector<int> b; //Empty vector

    setFormat("P3");
    setColumn(0);
    setRow(0);
    setRed(r);
    setGreen(g);
    setBlue(b);
}

Image::Image(string filename){
    downloadImage(filename);
}

// GETTERS
string Image::getFormat() const{
    return format;
}
int Image::getColumn() const{
    return column;
}
int Image::getRow() const {
    return row;
}
int Image::getMaxColor() const {
    return maxColor;
}
vector<int> Image::getRed() const {
    return red;
}
vector<int> Image::getGreen() const {
    return green;
}
vector<int> Image::getBlue() const {
    return blue;
}

// SETTERS
void Image::setFormat(string f){
    format = f;
}
void Image::setColumn(int c){
    column = c;
}
void Image::setRow(int r){
    row = r;
}
void Image::setMaxColor(int max){
    maxColor = max;
}
void Image::setRed(vector<int> r){
    red = r;
}
void Image::setGreen(vector<int> g){
    green = g;
}
void Image::setBlue(vector<int> b){
    blue = b;
}

void Image::downloadImage(string filename) {

    ifstream file; //file only read
    int r,g,b;  // Variables are going to read from file
    int count = 0;


    file.open(filename);
    
    file >> format >> column >> row >> maxColor;


    while(count < column*row){
        //Each time takes an 3 int value from file and push pack in vector respectively
        file >> r >> g >> b;
        red.push_back(r);
        green.push_back(g);
        blue.push_back(b);

        count++;
    }

    printDialogMenu();

    file.close();
}

void Image::uploadImage(string filename) const {

    ofstream file; // file only write

    // Write all object variables

    file.open(filename);
    file << format << endl;
    file << column << ' ' << row << endl;
    file << maxColor << endl;

    for(int i = 0; i < row*column; i++){
        file << red[i] << ' ' << green[i] << ' ' << blue[i];
        if((i+1) % column == 0){
            file << endl;
        }else{
            file << " ";
        }
    }
    file.close();
}

void Image::convertImage(double c_r, double c_g, double c_b){

    // Takes all the RGB vectors and modify them with given coefficients.


    int converted_r, converted_g, converted_b;

    for(int i = 0; i<row*column; i++){

        converted_r = (c_r * red[i]) + (c_g * green[i]) + (c_b * blue[i]);
        converted_g = (c_r * red[i]) + (c_g * green[i]) + (c_b * blue[i]);
        converted_b = (c_r * red[i]) + (c_g * green[i]) + (c_b * blue[i]);


        // If any value bigger then Max Color Value(255) Leave them as Max Color Value
        if(converted_r > maxColor){
            converted_r = maxColor;
        }
        if(converted_g > maxColor){
            converted_g = maxColor;
        }
        if(converted_b > maxColor){
            converted_b = maxColor;
        }

        red[i] = converted_r;
        green[i] = converted_g;
        blue[i] = converted_b;

    }

}

void Image::printDialogMenu() const {

    cout << format << endl;
    cout << column << " " << row << endl;
    cout << maxColor << endl;

    for(int i = 0; i<row*column; i++){

        cout << red[i] << ' ' << green[i] << ' ' << blue[i];
        if((i+1) % column == 0){
            cout << endl;
        }else{
            cout << " ";
        }
    }
    cout << endl;
}



void mainMenu(){

    // Create an empty Image Object and modify it along the main menu.
    Image img;
    int input = 0;

    do{
        cout << "MAIN MENU" << endl;
        cout << "0 - Exit" << endl;
        cout << "1 - Open An Image(D)" << endl;
        cout << "2 - Save Image Data(D)" << endl;
        cout << "3 - Script(D)" << endl;

        cin >> input; 

        switch (input)
        {
        case 0:
            //Exit
            break;

        case 1:
            openImageMenu(img);
            break;
        
        case 2:
            saveImageMenu(img);
            break;
        case 3:
            scriptMenu(img);
            break;

        default:
            cout << "Wrong Input!\n" << endl;
        }

    }while(input!=0);

   
}
void openImageMenu(Image& img){
    string filename;
    int input = 0;


    do{
        cout << "OPEN AN IMAGE MENU" << endl;
        cout << "0 - UP" << endl;
        cout << "1 - Enter The Name Of The File" << endl;

        cin >> input;

        switch (input)
        {
        case 0:
            //Go Back to Main Menu
            break;
        case 1:
            cin >> filename;
            img.downloadImage(filename);
            
            break;
        default:
            cout << "Wrong Input!" << endl;
            break;
        }

    } while(input != 0);

}
void saveImageMenu(Image& img){

    string filename;
    int input = 0;
    
    do {
        cout << "SAVE IMAGE DATA MENU" << endl;
        cout << "0 - UP" << endl;
        cout << "1 - Enter a File Name" << endl;
        cin >> input;

        switch (input){
            case 0:
                //Go Back to Main Menu
                break;
            
            case 1:
                cin >> filename;
                img.uploadImage(filename);
                break;
            
            default:
                cout << "Wrong Input!" << endl;
                break;
        }

    }while(input!=0);

}
void scriptMenu(Image& img){
    int input = 0;
    
    do {
        cout << "SCRIPT MENU" << endl;
        cout << "0 - UP" << endl;
        cout << "1 - Convert to Grayscale(D)" << endl;
        cin >> input;

        switch (input){
            case 0:
                //Go Back to Main Menu
                break;
            
            case 1:
                convertMenu(img);
                break;
            
            default:
                cout << "Wrong Input!" << endl;
                break;
        }

    }while(input!=0);
}

void convertMenu(Image& img){
    int input = 0;
    double c_r, c_g, c_b; //Coefficent for channels

    do {
        cout << "CONVERT TO GRAYSCALE MENU" << endl;
        cout << "0 - UP" << endl;
        cout << "1 - Enter Coefficients for RED GREEN and BLUE channels" << endl;
        cin >> input;

        switch (input){
            case 0:
                //Go Back to Main Menu
                break;
            
            case 1:
                
                do{
                    cin >> c_r >> c_g >> c_b;

                    //If coefficents are not in range (0,1] then reenter coefficents
                } while(c_r > 1 || c_r < 0 || c_g > 1 || c_g < 0 || c_b > 1 || c_b < 0);

                img.convertImage(c_r,c_g,c_b);
                break;
            
            default:
                cout << "Wrong Input!" << endl;
                break;
        }

    }while(input!=0);
}




int main(){

    Image img;
    //MENU
    mainMenu();

}   