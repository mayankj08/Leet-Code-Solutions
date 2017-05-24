#include<iostream>
#include<string>

std::string addBinary(std::string a,std::string b){
    
    auto iterA = a.end();
    auto iterB = b.end();
    bool isALeft;
    char carry = '0';
    std::string result = "";
    if(a.end() == a.begin())
        isALeft = false;
    else
        isALeft = true;


    bool isBLeft;
    if(b.end() == b.begin())
        isBLeft = false;
    else
        isBLeft = true;

    char charA,charB;

    while(1){

        /*std::cout << "Result:" << result << " " 
                  << "Carry:"  << carry  << " "
                  << "isALeft:" << isALeft << " "
                  << "isBLeft:" << isBLeft << " "
                  << '\n';*/
               
        if(isALeft){
            --iterA;
            charA = *iterA;
        }
        else{
            charA = '0';
        }


        if(isBLeft){
            --iterB;
            charB = *iterB;
        }
        else{
            charB = '0';
        }

        if(charA == '0' and charB == '0' and carry == '0'){
            result = "0" + result;
            carry = '0';
        }
        else if(charA == '0' and charB == '0' and carry == '1'){
            result = "1" + result;
            carry = '0';
        }
        else if(charA == '1' and charB == '1' and carry == '0'){
            result = "0" + result;
            carry = '1';
        }
        else if(charA == '1' and charB == '1' and carry == '1'){
            result = "1" + result;
            carry = '1';
        }
        else if((charA == '1' or charB == '1') and carry == '1'){
            result = "0" + result;
            carry = '1';
        }
        else if((charA == '1' or charB == '1') and carry == '0'){
            result = "1" + result;
            carry = '0';
        }
            
        
        if(iterA == a.begin())
            isALeft = false;

        if(iterB == b.begin())
            isBLeft = false;

        if(isALeft == false and isBLeft == false)
            break;
    }

    if(carry == '1')
        result = "1" + result;
    
    return result;
}

int main(){

    while(1){
        std::string a;
        std::string b;

        std::cin >> a >> b;
        std::cout << addBinary(a,b) << '\n';
    }
}
