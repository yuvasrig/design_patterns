//
//  bread_maker.cpp
//  bread_maker
//
//  Created by Yuvasri Govindasamy on 9/20/17.
//
//

#include "bread_maker.h"
using namespace std;

class MilkBreadMaker : public BreadMaker{
public:
    void configure_Bread(){
        _bread.set_dough_flour("All purpose");
        _bread.set_wet_ingredients(vector<string>({"Milk"}));
    }
    
};

class WheatBreadMaker : public BreadMaker{
public:
    void configure_Bread(){
        _bread.set_dough_flour("Wheat");
    }
};

class FruitBreadMaker : public BreadMaker{
public:
    void configure_Bread(){
        _bread.set_dough_flour("All purpose");
        _bread.set_dry_ingredients(vector<string>({"Tutty-Frutty"}));
    }

};

int main(){

    cout << "Available options:"<<endl;
    cout << "1. Milk Bread\n2. WheatBread\n3. FruitBread\n";
    cout << "Pick a number[1,2,3] - ";
    int option;
    cin >> option;
    while(option>3){
        cout <<"Pick 1,2 or 3 - ";
        cin>> option;
    }
    FruitBreadMaker fb_maker;
    WheatBreadMaker wb_maker;
    MilkBreadMaker mb_maker;

    switch(option){
        case 3:
            fb_maker.bake_bread();
            break;
        case 2:
            wb_maker.bake_bread();
            break;
        case 1:
            mb_maker.bake_bread();
    }
    return 0;
}
