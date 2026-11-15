#include<iostream>
using namespace std;
class Complex {
    //Attributes=Variables inside Class
    double real ;
    double img;
    public:
        Complex(double real=0 ,double img=0 ){
            cout<<"Initialization Object Complex"<<endl;
            this->real=real;
            this->img=img;
        }
        int getReal()const{
            return real;
        }

        int getImg()const{
            return img;
        }

        void setComplex(int real,int img){
            this->real=real;
            this->img=img;
        }
    
        void getComplex() const{
            //cout<<this->real<<this->real;
            if(real !=0){
                cout<<real;
            }
            if(img !=0 ){
               (img >0)?cout<<"+"<<img<<"j"<<endl:cout<<img<<"j"<<endl;
            }

        }
        Complex operator+ (const Complex & other) const { //c1+c2
            return Complex(this->real+other.real,this->img+other.img);
        }
        Complex operator+ (int x)const{ //c1+2
            return Complex(this->real+x,this->img);
        }

        Complex operator-(const Complex & c2)const{
            return Complex(this->real-c2.real,this->img-c2.img);
        }
        Complex operator-(int x)const{
            return Complex(this->real-x,this->img);
        }
        
        Complex operator*(const Complex & c2)const{//(4+2i)(5+3i)
            return Complex(
               (this->real*c2.real) - (this->img*c2.img), 
               (this->real*c2.img) +   (this->img*c2.real) 
            );
        }
        Complex operator*(int x)const{ //(A+bi)*3==>3A+3bi
            return Complex(this->real*x,this->img*x);
        }
        
        Complex operator/(const Complex&c2)const{//(4+2i)/(5+3i)==>(4+2i)(5-3i)/(5+3i)(5-3i) 
            double maqam = (this->real*c2.real)+(this->img*c2.img);
            if(maqam!=0){
                double newReal = ((this->real * c2.real) + (this->img * c2.img)) / maqam;
                double newImg  = ((this->img * c2.real) - (this->real * c2.img)) / maqam;
                return Complex (newReal,newImg);
            }else{
                cout<<"Can't devision by Zero!!"<<"\n";
                return Complex(0,0);
            }
        }
        Complex operator/(int x){//(4+2i)/3==>4/3 +2i/3
            if(x!=0){
               return Complex(this->real/x,this->img/x);
            }
            else{
                cout<<"Can't devision by ZERO!!"<<"\n";
                return Complex(0,0);
            }
        }
        Complex operator%(const Complex&c2)const{
            Complex result;
            if((int)c2.real!=0&&(int)c2.img!=0){
                result.real = (int)this->real%(int)c2.real;
                result.img = (int)this->img%(int)c2.img;
                return result;
            }else{
                cout<<"Can't modulo by ZERO!!"<<"\n";
                return Complex(0,0);
            }
        }
        Complex operator%(int x){
            if(x!=0){
                return Complex((int)this->real%x,(int)this->img%x);
            }else{
                cout<<"Can't modulo by ZERO!!"<<"\n";
                return Complex(0,0);
            }
        }
        
        //postfix
        Complex  operator++(int){
            Complex old = *this;
            this->real++;
            this->img++;
            return old;
        }
        Complex  operator--(int){
            Complex old = *this;
            this->real--;
            this->img--;
            return old;
        }
        //prefix
        Complex& operator++(){
            this->real++;
            this->img++;
            return *this;
        }
        Complex& operator--(){
            this->real--;
            this->img--;
            return *this;
        }

        friend Complex operator+ (int x,const Complex & c);
        friend Complex operator- (int x,const Complex & c);
        friend Complex operator* (int x,const Complex & c);
        friend Complex operator/ (int x,const Complex & c);
        friend Complex operator% (int x,const Complex & c);
};

//Standlone Function
/*Complex operator+ (const Complex & c,int x){
    return Complex(c.getReal()+x,c.getImg());
}*/
// Standlone Function
Complex operator+ (int x,const Complex & c){ //5+c1
    return Complex(c.real+x,c.img); //friend
    //return Complex(c.getReal()+x,c.getImg());
}

Complex operator- (int x,const Complex & c){ //5-c1
    return Complex(x-c.real,-c.img); //friend
    //return Complex(c.getReal()+x,c.getImg());
}

Complex operator* (int x ,const Complex & c){ 
   return Complex(c.real*x,c.img*x);
}

Complex operator/ (int x ,const Complex & c){ // 5/(10+5i)==>5(10-5i)/(10+5i)(10-5i)
   double maqam = (c.real*c.real)+(c.img*c.img);
   if(maqam!=0){ 
      
        return Complex((x*c.real)/maqam,-(x*c.img)/maqam);
   }
   else{
        cout<<"Can't devision by ZERO!!"<<"\n";
        return Complex(0,0);
   }
}

Complex operator% (int x ,const Complex & c){ 
    if((int)c.real!=0&&(int)c.img!=0){
        return Complex(x%(int)c.real,x%(int)c.img);
    }else{
        cout<<"Can't modulo by ZERO!!"<<"\n";
        return Complex(0,0);
    }
}



int main() {
Complex c1(10, 5);
Complex c2(3, 2);

cout << "===== Original Objects ====="<<"\n";
cout << "c1 = ";
c1.getComplex();

cout << "c2 = ";
c2.getComplex();

// 1. Add
cout << "===== Add (+) ====="<<"\n";
(c1 + c2).getComplex();
(c1 + 2).getComplex();
(5 + c1).getComplex();

//2.Sub
cout << "===== Sub (-) ====="<<"\n";
(c1 - c2).getComplex();
(c1 - 2).getComplex();
(5 - c1).getComplex();

//3.Mult
cout << "===== Mult (*) ====="<<"\n";
(c1 * c2).getComplex();
(c1 * 2).getComplex();
(5 * c1).getComplex();

//4.Divide
cout << "===== Divide (/) ====="<<"\n";
(c1 / c2).getComplex();
(c1 / 2).getComplex();
(5 / c1).getComplex();

//5.MOD
cout << "===== MOD (%) ====="<<"\n";
(c1 % c2).getComplex();
(c1 % 2).getComplex();
(5 % c1).getComplex();

//6.c++
cout << "===== postfix (c++) ====="<<"\n";
Complex c3(3,9);
c3++;
c3.getComplex();
//7.c--
cout << "===== postfix (c--) ====="<<"\n";
c3--;
c3.getComplex();
//8.++c
cout << "===== prefix (++c) ====="<<"\n";
++c3;
c3.getComplex();
//8.--c
cout << "===== prefix (--c) ====="<<"\n";
--c3;
c3.getComplex();




return 0;
}