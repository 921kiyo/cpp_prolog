#include <iostream>

#include <string>
#include <vector>

using namespace std;

class Nuts{
  double fat_portion;
  double weight;
  // Bag *being_in_bag;
public:
  Nuts(double f){
    fat_portion = f;
    being_in_bag = NULL;
  }
  void added(Bag* b){
    being_in_bag = b;
  }
  double calculate_energy(){
    double fat = weight * fat_portion;
    double non_fat = weight * (1 - fat_portion);
    double energy = 9*fat;
    energy = energy + 4*non_fat;

    return energy;
  }
  double get_fat(){
    return fat_portion;
  }
  double get_weight(){
    return weight;
  }
};


class Bag{
  vector<Nuts*> nuts;
  int capacity;
  double calculate_fat(){

    double total = 0;
    for(vector<Nuts*>::iterator it = nuts.begin(); it != nuts.end(); it++){
      double a = it->get_fat();
      cout << a << endl;
    }
    return total;
  }
  double calculate_energy(){
    double total = 0;
    return total;
  }
public:
  Bag(int limit){
    capacity = limit;
    // for (int i = 0; i < limit; i++){
    //   nuts.push_back(NULL);
    // }
  }
  // change label

  // Create BNI
  // create label with BNI
  // 
  void add_tag(){

  }
  void add_nuts(Nuts* nut){
    nuts.push_back(nut);
    nut->added(this);
  }
  void get_bni(){
    int fat = calculate_fat();
    int energy = calculate_fat();
    cout << "Total of " << energy << " kcal (" << fat << " g fat";
    if(fat >= 20){
      cout << "[high in fat]";
    }
    cout << endl;
  }
};


class Walnut: public Nuts{
public:
  Walnut(): Nuts(65.21){}
};

class Almond: public Nuts{
public:
  Almond(): Nuts(50.64){}
};

int main(){
  Bag bag(8);
  Walnut walnut;
  Walnut almond;
  bag.add_nuts(&walnut);
  bag.add_nuts(&almond);
  bag.add_tag();
  bag.get_bni();
  Walnut walnut2;
  bag.add_nuts(&walnut2);
  bag.add_tag();
  bag.get_bni();
  return 0;
}
