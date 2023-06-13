#include <iostream>

using namespace std;

class Polynomial{
    public:

        Polynomial(){
            coefficents = NULL;
            int size = 0;

        }
        Polynomial(const Polynomial& cpy){
            coefficents = new double[cpy.size];
            coefficents = cpy.coefficents;
            size = cpy.size;
        }

        Polynomial(double arr[], int s) : size(s){
            coefficents = new double[s];
            for(int i=0; i < s; i++){
                coefficents[i] = arr[i];
            }
            
        }
        
        ~Polynomial(){
            delete [] coefficents;
        }

        const Polynomial& operator= (const Polynomial& other){
            

            if(coefficents == other.coefficents){
                return other;
            }
            else{
                delete [] coefficents;
                coefficents = new double[other.size];
                for(int i=0; i<other.size;i++){
                    coefficents[i] = other.coefficents[i];
                }
                size = other.size;
            }
            return other;
        }

        Polynomial operator+ (const Polynomial& other){
            Polynomial temp;
            temp.size = this->size > other.size ? this->size : other.size;
            temp.coefficents = new double[temp.size];


            if(other.size > this->size){

                for(int i=0; i<this->size; i++){
               
                    temp.coefficents[i] = coefficents[i] + other.coefficents[i];

                }
                for(int i=this->size; i<other.size; i++){
                    temp.coefficents[i] = other.coefficents[i];
                }

            }else{

                for(int i=0; i<other.size; i++){
               
                    temp.coefficents[i] = coefficents[i] + other.coefficents[i];

                }
                for(int i=other.size; i<this->size; i++){
                    temp.coefficents[i] = this->coefficents[i];
                }

            }
            
            
            return temp;
        }   

        Polynomial operator- (const Polynomial& other){
            Polynomial temp;
            temp.size = this->size > other.size ? this->size : other.size;
            temp.coefficents = new double[temp.size];

           if(other.size > this->size){

                for(int i=0; i<this->size; i++){
               
                    temp.coefficents[i] = coefficents[i] - other.coefficents[i];

                }
                for(int i=this->size; i<other.size; i++){
                    temp.coefficents[i] = 0-other.coefficents[i];
                }

            }else{

                for(int i=0; i<other.size; i++){
               
                    temp.coefficents[i] = coefficents[i] - other.coefficents[i];

                }
                for(int i=other.size; i<this->size; i++){
                    temp.coefficents[i] = 0 - this->coefficents[i];
                }

            }
            
            return temp;
        }   

        Polynomial operator* (const Polynomial& other) {
            Polynomial temp;
            temp.size = (other.size + this->size) - 1;
            temp.coefficents = new double[temp.size];

            for(int i =0; i < temp.size; i++){
                temp.coefficents[i] = 0;
            }

            for(int i=0; i < this->size; i++){
                for(int j = 0; j < other.size; j++){
                    temp.coefficents[i+j]+= other.coefficents[j] * this->coefficents[i];
                }
            }

            return temp;
        }


        double& operator[](int degree){
            return coefficents[degree];
        }

        const double& operator[](int degree) const{
            return coefficents[degree];
        }

        
    double& getCoeff(){
        return *coefficents;
    }
    int mySize(){
        return size;

    }

    friend double evaluate(const Polynomial& pol, double arg);


    private:

        double* coefficents;
        int size;

};


double evaluate(const Polynomial& pol, double arg){
    double total=0;
    for(int i=pol.size-1; i>=0 ; i--){
        total = pol[i] + arg * total;
    }
    return total;
}





int main(){
    Polynomial empty;
double one[] = {1};
Polynomial One(one, 1);
double quad[] = {3, 2, 1};
double cubic[] = {1, 2, 0, 3};
Polynomial q(quad, 3); // q is 3 + 2*x + x*x
Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x Polynomial p = q; // test copy constructor
Polynomial r;
r = q; //test operator=
r = c;
cout << "Polynomial q " << endl; for(int i = 0; i < 3; i++){
     cout << "term with degree " << i
          << " has coefficient " <<  q[i] << 
          endl;
}
cout << "Polynomial c " << endl; {for(int i = 0; i < 4; i++)
     cout << "term with degree " << i
          << " has coefficient " <<  c[i] << 
          endl;
   }
   cout << "value of q(2) is " << evaluate(q, 2) << endl;

   cout << "value of r(2) is " << evaluate(r, 2) << endl;
   cout << "value of c(2) is " << evaluate(c, 2) << endl;
   r = q + c;
   cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;
   r = q - c;
   cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;
   r = q * c;
   cout << "size of q*c is " << r.mySize() << endl;
   cout << "Polynomial r (= q*c) " << endl;
for(int i = 0; i < r.mySize(); i++) cout << "term with degree " << i
          << " has coefficient " <<  r[i] << endl;
   cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
return 0;
}