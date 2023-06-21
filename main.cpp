#include <iostream>
#include <yaml-cpp/yaml.h>
#include <fstream>


void writeData()
{
    YAML::Node yamlData;

    // create variables
    yamlData["name"] = "Lucas Smith";
    yamlData["age"] = 28;

    // Create a sub-class
    YAML::Node addressNode;
    addressNode["street"] = "123 Main St";
    addressNode["city"] = "Anytown";
    addressNode["country"] = "USA";

    // Assign the sub-class to the main node
    yamlData["address"] = addressNode;

    // create more of one class
    yamlData["interests"].push_back("Programming");
    yamlData["interests"].push_back("Eating");
    yamlData["interests"].push_back("Sleeping");
    
    // Write the YAML data to a file
    std::ofstream file("values.yaml");
    file << yamlData;
}

void readData(YAML::Node yamlData)
{
    std::string name = yamlData["name"].as<std::string>();
    int age = yamlData["age"].as<int>();

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}

int main()
{
    writeData();
    
    YAML::Node yamlData = YAML::LoadFile("values.yaml");
    readData(yamlData);




    return 0;
}