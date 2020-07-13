#include "monitor.h"
#include <vector>
#include <typeinfo>
//#define DEBUG

Monitor::Monitor(Arm* arm){
    #ifdef DEBUG
    std::cout << "Monitor have arm with " << arm->links.size() << "links" << std::endl;
    #endif
    this->arm = arm;
}

Monitor::~Monitor(){
    #ifdef DEBUG
    std::cout << "Monitor had:" << this->obstacles.size() << "obstacles before destruction" << std::endl;
    #endif //DEBUG
    for( int i=0; i < this->obstaclesToDelete.size(); i++){
        delete obstaclesToDelete[i];
        obstaclesToDelete[i] = NULL;
    }
}

void Monitor::addObstacle(Primitive* obstacle) {
    #ifdef DEBUG
    std::cout << "[Monitor] obstacle root method, received obstacle" << std::endl;
    #endif //DEBUG
    Capsule *capsule = dynamic_cast<Capsule*>(obstacle);
    if(capsule){
        this->addObstacle(capsule);
    }else{
        Sphere *sphere = dynamic_cast<Sphere*>(obstacle);
        if(sphere){
            this->addObstacle(sphere);
        }
    }

}

void Monitor::addObstacle(Sphere* obstacle) {
    #ifdef DEBUG
    std::cout << "[Monitor] obstacle sphere method" << std::endl;
    #endif
    Sphere* obstacleCopy = new Sphere(obstacle);
    obstaclesToDelete.push_back(obstacleCopy);
    obstacles.push_back(obstacleCopy);
}

void Monitor::addObstacle(Capsule* obstacle) {
    #ifdef DEBUG
    std::cout << "[Monitor] obstacle capsule method" << std::endl;
    #endif
    Capsule* obstacleCopy = new Capsule(obstacle);
    obstaclesToDelete.push_back(obstacleCopy);
    obstacles.push_back(obstacleCopy);
}


void Monitor::addObstacle(Arm* arm_obstacle) {
    #ifdef DEBUG
    std::cout << "[Monitor] obstacle arm method" << std::endl;
    #endif
    // Adds every link of the arm (a primitive) to the obstacles vector.
    for (int i = 0; i < arm_obstacle->links.size(); i++) {
        // this->obstacles.push_back(arm->links[i]);
        #ifdef DEBUG
        std::cout << "link ["<< i << "]\n" << arm_obstacle->links[i]->pose << std::endl;
        #endif
        obstacles.push_back(arm_obstacle->links[i]);
    }
    #ifdef DEBUG
    std::cout << "[Monitor] new obstacle length: " << obstacles.size() << std::endl;
    #endif
}

std::vector<std::vector<double>> Monitor::distanceToObjects(){

    std::vector<std::vector<double>> distanceToObjects;

    // For every obstacle calculate the distaces to each link
    for (int i = 0; i < this->obstacles.size(); i++ ) {
        
        std::vector<double> distances;

        for (int j = 0; j < this->arm->links.size(); j++) {
            
            distances.push_back(this->arm->links[j]->getShortestDistance( 
                this->obstacles[i] ));
        }
        
        distanceToObjects.push_back(distances);
    }

    #ifdef DEBUG
    // prints the distances calculated
    for (int i = 0; i < distanceToObjects.size(); i++) {
        std::cout << "distances to obstacle [" << i << "]:";

        for (int j = 0; j < distanceToObjects[i].size(); j++){
            std::cout << distanceToObjects[i][j] << " "; 
        }
        std::cout << std::endl;
    }
    #endif //DEBUG

    return distanceToObjects;
}

std::vector<std::vector<double>> Monitor::distanceBetweenArmLinks(){
    
    std::vector<std::vector<double>> distanceToObjects;

    // For every link calculate the distance to other links
    for (int i = 0; i < this->arm->links.size(); i++) {

        std::vector<double> distances;
        for (int j = 0; j < this->arm->links.size(); j++) {
            if (i != j) {
                distances.push_back(this->arm->links[i]->getShortestDistance(
                    this->arm->links[j]));
            } else {
                distances.push_back(0);
            }
        }
        distanceToObjects.push_back(distances);
    }

    #ifdef DEBUG
    // print the calculated distances.
    for (int i = 0; i < distanceToObjects.size(); i++) {
        std::cout << "distances from link [" << i << "] to other links:";

        for (int j = 0; j < distanceToObjects[i].size(); j++){
            std::cout << distanceToObjects[i][j] << " "; 
        }
        std::cout << std::endl;
    }
    #endif //DEBUG

    return distanceToObjects;
}