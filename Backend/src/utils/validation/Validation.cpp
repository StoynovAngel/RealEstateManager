#include "Validation.h"

namespace Validation{

    bool isNotEmpty(std::string& value){
        return !value.empty();
    }
    bool isEgnCorrect(std::string& egn){
        if(!isNotEmpty(egn)) return false; 
        if(egn.size() != 10) return false;

        for(char c: egn){
            if(!std::isdigit(c)) return false;
        }

        return true;
    }
}