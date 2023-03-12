#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct() //is the class name
{
    //before define geometry, you need to define material
    G4NistManager *nist = G4NistManager::Instance(); //use this manager to get the parameter for different material
    
   
    
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

    //need a world volume
    //whenever we create detector we need 3 volume
    G4Box *solidWorld = new G4Box("solidWorld",0.5*m,0.5*m,0.5*m); //half size of x,y,z in mm,with m convert it in m unit
    //logical volume
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld,worldMat,"logicaWorld");

    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),logicWorld, "physWorld",0, false, 0, true);


    return physWorld; //return the hightest mother volume






}