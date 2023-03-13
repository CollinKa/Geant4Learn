#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4SystemOfUnits.hh"

#include "detector.hh"

//inherate
class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    virtual G4VPhysicalVolume *Construct();// construct() is the main function
    // virtual function is due to the class G4VPhysicalColume is defined in G4UserDetectorConstruction
    
private:
    G4LogicalVolume *logicDetector;
    virtual void ConstrutSDandField();
};


#endif