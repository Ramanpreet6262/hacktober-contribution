/*
    Author: Piyush Garg
 */

#include <iostream>


using namespace std;

class Interest{
    private:
    float p,r,t;
    
    int power(float x, float t)
    {
        float result = x;
        for(int i=0;i<t;i++){
            result *= result;
        }
        return result;

    }
    public:
    Interest(float principalAmt, float rate, float time){
        this->p = principalAmt;
        this->r = rate;
        this->t = time;
    }
    int SI(){return this->p*this->r*this->t/100;}
    int CI(float n){return this->p*power((1+this->r/n),this->t);}
};

int main(){
    /*
        Write your code here
     */
}
