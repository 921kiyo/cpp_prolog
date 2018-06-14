#include <iostream>

#include <string>

using namespace std;


class StorageDevice{
protected:
  double _capacity;
  double _bandwidth;
public:
  StorageDevice(double capacity, double bandwidth){
    _capacity = capacity;
    _bandwidth = bandwidth;
  }

  virtual double latency() = 0;

  double bandwidth() const { return _bandwidth;}
  double capacity() const { return _capacity; }
};

class HardDisk: public StorageDevice{
double average_rotation;
double average_seek;

public:
  HardDisk(double cap, double band, double seek, double rotation): StorageDevice(cap, band){
    average_seek = seek;
    average_rotation = rotation;
  }

  virtual double latency(){
    return  average_rotation + average_seek;
  }
};

class SolidStateDisk: public StorageDevice{
double memory_access_time;

public:
  SolidStateDisk(double cap, double band, double access, double): StorageDevice(cap, band){
    memory_access_time = access;
  }

  virtual double latency(){
    return memory_access_time;
  }
};


class StorageArray{
protected:
  int devices;
  StorageDevice *device[12];

public:
  StorageArray(){
    devices = 0;
    for(int i = 0; i < 12; i++){
      device[i] = NULL;
    }
  }

  bool add_device(StorageDevice *dev){
    for(int i = 0; i < 12; i++){
      if(device[i] == NULL){
        device[i] = dev;
        return true;
      }
    }
    return false;
  }

  double latency(){
    double max = 0;
    for(int i = 0; i < 12; i++){
      if(max < device[i]->latency()){
        max = device[i]->latency();
      }
    }
    return max;
  };

  virtual double effective_capacity()=0;

};

class RAID1: public StorageArray{
  double scale_factor;
public:
  RAID1(): StorageArray(){}
  double effective_capacity(){
    double sum = 0;
    for(int i = 0; device[i] != NULL; i++){
      sum = sum + device[i]->bandwidth();
    }
    return sum;
  }
};

class RAID5: public StorageArray{
  double scale_factor;
public:
  RAID5(): StorageArray(){}
  double effective_capacity(){
    double sum = 0;
    for(int i = 0; device[i] != NULL; i++){
      sum = sum + device[i]->bandwidth();
    }
    return sum;
  }

};

int main(){
  RAID1 raid1;
  HardDisk h1(500, 100, 8, 4);
  HardDisk h2(500, 100, 8, 4);
  HardDisk h3(500, 100, 8, 4);
  HardDisk h4(500, 100, 8, 4);
  raid1.add_device(&h1);
  raid1.add_device(&h2);
  raid1.add_device(&h3);
  raid1.add_device(&h4);

  RAID5 raid5;
  HardDisk h5(30, 0.01, 300, 4);
  HardDisk h6(30, 0.01, 300, 4);
  HardDisk h7(30, 0.01, 300, 4);
  HardDisk h8(30, 0.01, 300, 4);
  raid5.add_device(&h5);
  raid5.add_device(&h6);
  raid5.add_device(&h7);
  raid5.add_device(&h8);

  cout << "RAID1 latency is " << raid1.latency() << endl;
  cout << "The effective capacity of the RAID5 is " << raid5.latency() << endl;

  return 0;
}
