//
//  bread_maker.h
//  bread_maker
//
//  Created by Yuvasri Govindasamy on 9/20/17.
//
//


#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>


using namespace std;
class BreadMaker;

class Ingriedients{
    vector<string> items;
    
public:
    Ingriedients():items(vector<string>({})){}
    
    Ingriedients& operator+=(vector<string> items){
        for(auto it: items) {
            this->items.push_back(it);
        }
        return *this;
    }
    
    friend ostream &operator<<( ostream &output, const  Ingriedients &i) {
        for(auto it:i.items){
            output << it << " ,";
        }
        output <<'\b';
        return output;
    }
};
class Bread{
    string _dough_flour;
    Ingriedients _dry_ingredients;
    Ingriedients _wet_ingredients;
    
public:

    Bread() {
      _dry_ingredients += vector<string>({"Baking Soda", "Salt", "Yeast"});
      _wet_ingredients += vector<string>({"Water", "Vanilla Essense"});
    }
                             
    void set_dough_flour(string flour){
        _dough_flour = flour;
    }
    
    void set_wet_ingredients(vector<string> ingredients){
        _wet_ingredients += ingredients;
    }
    
    void set_dry_ingredients(vector<string> ingredients){
        _dry_ingredients += ingredients;
    }
    
    void display_ingriedients(){
        cout << "The bread contains:"<<endl;
        cout << "Dough: " << _dough_flour<<endl;
        cout << "Wet Ingredients: "<<_wet_ingredients<<endl;
        cout << "Dry Ingredients: "<<_dry_ingredients<<endl;
    }
        
};

class BreadMaker{
protected:
    Bread _bread;
public:
    virtual void configure_Bread() = 0;
    void bake_bread(){
        configure_Bread();
        _bread.display_ingriedients();
        cout << "Mix and send ingriedients to the oven"<<endl;

    }
};
