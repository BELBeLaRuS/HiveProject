#include <iostream> 
#include <vector>
#include <string>
using namespace std;

class Bee {
protected: 
    int age; 
    int honeyConsumption;

public: 
    int getHoneyConsumption();
};

class QueenBee : public Bee {
private: 
    int eggProduction;

public: 
    QueenBee(int _eggProduction, int _age) : eggProduction(_eggProduction), 
        Bee() { age = _age; honeyConsumption = calculateHoneyConsumption(); }


      int getHoneyConsumption() {
          return honeyConsumption;
      }

      int calculateHoneyConsumption() {
          return eggProduction * age;
      }
};

class WorkerBee : public Bee {
private: int flightDistance;

public: WorkerBee(int _flightDistance, int _age) : flightDistance(_flightDistance), Bee() { age = _age; honeyConsumption = calculateHoneyConsumption(); }


      int getHoneyConsumption() {
          return honeyConsumption;
      }

      int calculateHoneyConsumption() {
          return flightDistance * age;
      }
};

class Hive {
private: string constructionType; int length; int width; int height; string material; int removableFrames; vector<Bee*> bees;

public: void addBee(Bee* bee) { bees.push_back(bee); }


      void removeBee(int index) {
          bees.erase(bees.begin() + index);
      }

      void removeBee(Bee* bee) {
          for (int i = 0; i < bees.size(); i++) {
              if (bees[i] == bee) {
                  bees.erase(bees.begin() + i);
                  break;
              }
          }
      }

      Bee* getBee(int index) {
          return bees[index];
      }

      int getTotalBees() {
          return bees.size();
      }

      int getBeesOfType(string type) {
          int count = 0;
          for (int i = 0; i < bees.size(); i++) {
          }
          return count;
      }

      string getFullInfo() {
          string info = "";
          return info;
      }

      string getHiveInfo() {
          return "Hive Construction Type: " + constructionType + "\nDimensions: " + std::to_string(length) + " x " + std::to_string(width) + " x " + std::to_string(height) 
              + "\nMaterial: " + material + "\nRemovable Frames: " + std::to_string(removableFrames);
      }
};

int main() {
    Hive hive; 
    QueenBee queen(100, 10); 
    WorkerBee worker(5, 15); 
    hive.addBee(&queen); 
    hive.addBee(&worker);


    cout << hive.getFullInfo() << std::endl;
    cout << hive.getHiveInfo() << std::endl;

    return 0;
}