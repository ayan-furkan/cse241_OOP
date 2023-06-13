#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


class ppmImage{

    public:

        //CONSTRUCTORS
        ppmImage();
        ppmImage(string filename);
        ppmImage(const ppmImage& copy);

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

        ppmImage operator+(const ppmImage& other);
        ppmImage operator-(const ppmImage& other);
        int& operator()(const int r, const int c, const int colorChannel); //Access the RGB value
        friend ostream& operator<<(ostream& os, const ppmImage& image); // print dialog

        int downloadImage(string filename); // modify the object from given ppm file
        int uploadImage(string filename) const; // upload the object to given file name
        void convertImage(double c_r, double c_g, double c_b); // Enter 3 coefficents and modify the RGB variables

        void printDialogMenu() const; //Dialog menu include all the private member that object has


        



    private:
        string format; // "P3"
        int column , row , maxColor;
        vector<int> red; 
        vector<int> green;
        vector<int> blue;

};

int read_ppm(const string source_ppm_file_name, ppmImage& destination_object){

    ppmImage tempObj;
    if(tempObj.downloadImage(source_ppm_file_name)){
        
        destination_object.setFormat(tempObj.getFormat());
        destination_object.setColumn(tempObj.getColumn());
        destination_object.setRow(tempObj.getRow());
        destination_object.setMaxColor(tempObj.getMaxColor());
        destination_object.setRed(tempObj.getRed());
        destination_object.setGreen(tempObj.getGreen());
        destination_object.setBlue(tempObj.getBlue());

        return 1; //If everything successful return1
    }
    
    return 0; //Problem accuerd

}
int write_ppm(const string destination_ppm_file_name, const ppmImage& source_object){

    if(source_object.uploadImage(destination_ppm_file_name)) return 1;
    return 0;

}
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3){

    ppmImage img1, img2;
    if(!read_ppm(filename_image1, img1) || !read_ppm(filename_image2, img2)) return 0;

    if(!write_ppm(filename_image3, (img1 + img2))) return 0;

    return 1;
}
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3){

    ppmImage img1, img2;

    if(!read_ppm(filename_image1, img1) || !read_ppm(filename_image2, img2)) return 0;
    if(!write_ppm(filename_image3, (img1 - img2))) return 0;

    return 1;
}
int test_print(const string filename_image1){

    ppmImage img1;

    if(!read_ppm(filename_image1, img1)) return 0;

    cout << img1;

    return 1;

}
int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice){

    int col = image_object_to_be_modified.getColumn();
    int row = image_object_to_be_modified.getRow();
    int temp;


    switch (swap_choice)
    {
    case 1:
        cout << 1;
        for(int i=0; i < row; i++){
            for(int j = 0; j < col; j++){
                temp = image_object_to_be_modified(i,j,1);
                image_object_to_be_modified(i,j,1) = image_object_to_be_modified(i,j,2);
                image_object_to_be_modified(i,j,2) = temp;
            }
        }
        return 1;
        break;

    case 2:
        for(int i=0; i < row; i++){
            for(int j = 0; j < col; j++){
                temp = image_object_to_be_modified(i,j,1);
                image_object_to_be_modified(i,j,1) = image_object_to_be_modified(i,j,3);
                image_object_to_be_modified(i,j,3) = temp;
            }
        }
        return 1;
        break;

    case 3:
        for(int i=0; i < row; i++){
            for(int j = 0; j < col; j++){
                temp = image_object_to_be_modified(i,j,2);
                image_object_to_be_modified(i,j,2) = image_object_to_be_modified(i,j,3);
                image_object_to_be_modified(i,j,3) = temp;
            }
        }
        return 1;
        break;
    default:
        return 1;
        break;
    }

    return 0;
}
ppmImage single_color(const ppmImage& source, int color_choice){

    ppmImage newImage(source);
    int row = newImage.getRow();
    int column = newImage.getColumn();

    switch (color_choice)
    {
    case 1:
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                newImage(i,j,2) = 0;
                newImage(i,j,3) = 0;
            }
        }
        break;
    
    case 2:
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                newImage(i,j,1) = 0;
                newImage(i,j,3) = 0;
            }
        }
        break;
    
    case 3:
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                newImage(i,j,1) = 0;
                newImage(i,j,2) = 0;
            }
        }
        break;

    default:
        break;
    }

    return newImage;
}




ppmImage::ppmImage(){
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

ppmImage::ppmImage(string filename){
    downloadImage(filename);
}

ppmImage::ppmImage(const ppmImage& copy){

    format = copy.format;
    column = copy.column;
    row = copy.row;
    maxColor = copy.maxColor;
    red = copy.red;
    green = copy.green;
    blue = copy.blue;

}

// GETTERS
string ppmImage::getFormat() const{
    return format;
}
int ppmImage::getColumn() const{
    return column;
}
int ppmImage::getRow() const {
    return row;
}
int ppmImage::getMaxColor() const {
    return maxColor;
}
vector<int> ppmImage::getRed() const {
    return red;
}
vector<int> ppmImage::getGreen() const {
    return green;
}
vector<int> ppmImage::getBlue() const {
    return blue;
}

// SETTERS
void ppmImage::setFormat(string f){
    format = f;
}
void ppmImage::setColumn(int c){
    column = c;
}
void ppmImage::setRow(int r){
    row = r;
}
void ppmImage::setMaxColor(int max){
    maxColor = max;
}
void ppmImage::setRed(vector<int> r){
    red = r;
}
void ppmImage::setGreen(vector<int> g){
    green = g;
}
void ppmImage::setBlue(vector<int> b){
    blue = b;
}
int ppmImage::downloadImage(string filename) {

    ifstream file; //file only read
    int r,g,b;  // Variables are going to read from file
    int count = 0;


    file.open(filename);

    if(!file.is_open()) return 0; //not succesfully opened

    file >> format >> column >> row >> maxColor;


    while(count < column*row){
        //Each time takes an 3 int value from file and push pack in vector respectively
        file >> r >> g >> b;
        red.push_back(r);
        green.push_back(g);
        blue.push_back(b);

        count++;
    }

    file.close();

    return 1; // Operation succesfull
}

int ppmImage::uploadImage(string filename) const {

    ofstream file; // file only write

    // Write all object variables

    file.open(filename);

    if(!file.is_open()) return 0;

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

    return 1;
}

void ppmImage::convertImage(double c_r, double c_g, double c_b){

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

void ppmImage::printDialogMenu() const {

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


ppmImage ppmImage::operator+(const ppmImage& other){

    ppmImage obj;

    vector<int> newRed;
    vector<int> newGreen;
    vector<int> newBlue;


    //Check first they are the same size
    if((this->getColumn() != other.getColumn()) || (this->getRow() != other.getRow())){
        //If they are not the same size return empty object
        return obj;
    }

    for(int i=0; i<(row*column); i++){

        if((red[i] + other.red[i]) > 255){
            newRed.push_back(255);
        }
        else newRed.push_back(red[i] + other.red[i]);

        if((green[i] + other.green[i]) > 255){
            newGreen.push_back(255);
        }
        else newGreen.push_back(green[i] + other.green[i]);

        if((blue[i]+ other.blue[i]) > 255){
            newBlue.push_back(255);
        }
        else newBlue.push_back(blue[i] + other.blue[i]);
    }

    obj.setFormat(this->format);
    obj.setMaxColor(this->maxColor);
    obj.setColumn(this->column);
    obj.setRow(this->row);
    obj.setRed(newRed);
    obj.setGreen(newGreen);
    obj.setBlue(newBlue);

    return obj;

}

ppmImage ppmImage::operator-(const ppmImage& other){

    ppmImage obj;

    vector<int> newRed;
    vector<int> newGreen;
    vector<int> newBlue;


    //Check first they are the same size
    if((this->getColumn() != other.getColumn()) || (this->getRow() != other.getRow())){
        //If they are not the same size return empty object
        return obj;
    }

    for(int i=0; i<(row*column); i++){

        if((red[i] - other.red[i]) < 0){
            newRed.push_back(0);
        }
        else newRed.push_back(red[i] - other.red[i]);

        if((green[i] - other.green[i]) < 0){
            newGreen.push_back(0);
        }
        else newGreen.push_back(green[i] - other.green[i]);

        if((blue[i] - other.blue[i]) < 0){
            newBlue.push_back(0);
        }
        else newBlue.push_back(blue[i] - other.blue[i]);
    }

    obj.setFormat(this->format);
    obj.setMaxColor(this->maxColor);
    obj.setColumn(this->column);
    obj.setRow(this->row);
    obj.setRed(newRed);
    obj.setGreen(newGreen);
    obj.setBlue(newBlue);

    return obj;

}

ostream& operator<<(ostream& os, const ppmImage& image){

    os << image.getFormat() << endl;
    os << image.getColumn() << " " << image.getRow() << endl;
    os << image.getMaxColor() << endl;


    for(int i = 0; i<(image.getRow()*image.getColumn()); i++){

        os << image.getRed()[i] << ' ' << image.getGreen()[i] << ' ' << image.getBlue()[i];
        if((i+1) % image.getColumn() == 0){
            os << endl;
        }else{
            os << " ";
        }
    }
    os << endl;


    return os;

}

int& ppmImage::operator()(const int r, const int c, const int colorChannel){

    
    switch (colorChannel)
    {
    case 1:
        return this->red[(r*this->getColumn()) + c];
        break;
    
    case 2:
        return this->green[(r*this->getColumn()) + c];
        break;
    
    case 3:
        return this->blue[(r*this->getColumn()) + c];

        break;
    
    default:    
        cout << "OutOFINDEX" << endl;
        exit(1);
        break;
    }

}






int main(int argc, char** argv){

    if(argc != 5) {
        cout << "ERROR!(argc value)" << endl;
        exit(1);
    }

    ppmImage obj;


    switch (argv[1][0])
    {
    case '1':

        // Add first and second file then write to third file

        if(!test_addition(argv[2], argv[3], argv[4])){
             cout << "EXIT!";
             exit(1);
        }
        break;

    case '2':

        // Sub second file from first file then write to third file

        if(!test_subtraction(argv[2], argv[3], argv[4])){
            cout << "EXIT!";
             exit(1);
        }
        break;

    case '3':

        //Read first file swap red and blue channels then write to second file
        
        read_ppm(argv[2],obj);
        swap_channels(obj, 2);
        write_ppm(argv[3], obj);
        break;

    case '4':

        //Read first file, swap green and blue channels then werite to second file

        read_ppm(argv[2],obj);
        swap_channels(obj, 3);
        write_ppm(argv[3], obj);
        break;

    case '5':

        //Read first file, keep only red channels values then write to second file

        read_ppm(argv[2], obj);
        write_ppm(argv[3], single_color(obj,1));
        break;

    case '6':

        //Read first file, keep only green channels values then write to second file

        read_ppm(argv[2], obj);
        write_ppm(argv[3], single_color(obj,2));
        break;

    case '7':

        //Read first file, keep only blue channels values then write to second file

        read_ppm(argv[2], obj);
        write_ppm(argv[3], single_color(obj,3));
        break;


    default:
        cout << "Wrong Choice!\n";
        exit(1);
        break;
    }


}   