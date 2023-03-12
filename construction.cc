#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct() //is the class name
{
    //before define geometry, you need to define material
    G4NistManager *nist = G4NistManager::Instance(); //use this manager to get the parameter for different material
    
    G4Material *SiO2 = new G4Material("SiO2", 2.201*g/cm3,2); 
    SiO2 ->AddElement(nist->FindOrBuildElement("Si"),1);
    SiO2 ->AddElement(nist->FindOrBuildElement("O"),2);

    G4Material *H2O = new G4Material("H2O", 1.000*g/cm3,2); 
    H2O ->AddElement(nist->FindOrBuildElement("H"),2);
    H2O ->AddElement(nist->FindOrBuildElement("O"),1);

    G4Element *C = nist->FindOrBuildElement("C");


    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

    //need a world volume
    //whenever we create detector we need 3 volume
    G4Box *solidWorld = new G4Box("solidWorld",0.5*m,0.5*m,0.5*m); //half size of x,y,z in mm,with m convert it in m unit
    //logical volume
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld,worldMat,"logicaWorld");

    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),logicWorld, "physWorld",0, false, 0, true);


    return physWorld; //return the hightest mother volume






}