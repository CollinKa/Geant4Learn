#include "detector.hh"
#include <iostream>

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{

}
MySensitiveDetector::~MySensitiveDetector()
{

}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
    //position of photon
    G4Track *track = aStep->GetTrack();

    track->SetTrackStatus(fStopAndKill);//when pothon enter detector it is kill

    //when the photon enter the sensitive detector
    G4StepPoint *preStepPoint = aStep->GetPreStepPoint(); //prepoint: photon enter detector
    G4StepPoint *posStepPoint = aStep->GetPostStepPoint(); //posepoint: phton exist detector


    G4ThreeVector posPhoton = preStepPoint->GetPosition();

    std::cout << "Photon position: " << posPhoton<<std::endl;
    G4cout << "Photon position: " << G4endl;

    const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

    G4int copyNo = touchable->GetCopyNumber();

    G4cout << "copy num:" << copyNo << G4endl;


    G4VPhysicalVolume *physVol = touchable->GetVolume();
    G4ThreeVector posDetector = physVol->GetTranslation();

    G4cout << "Detector position:" <<posDetector << G4endl;
    //return true;
}