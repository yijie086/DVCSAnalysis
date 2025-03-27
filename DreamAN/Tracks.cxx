 #include "Tracks.h"
 #include <iostream>

 Tracks::Tracks(const int part)
     : fIsReset(false),
       fP(part),
       fIDTracks(0),
       fCharge(0),
       fInvMass(0),
       fZVtx(0),
       fPDGCode(0),
       fID(0),
       fEvtNumber(0),
       fChi2(0),
       fUse(true),
       fIsSet(true) {
 }
 
 Tracks::Tracks(const Tracks &part)
     : fIsReset(part.fIsReset),
       fP(part.fP),
       fIDTracks(part.fIDTracks),
       fCharge(part.fCharge),
       fInvMass(part.fInvMass),
       fZVtx(part.fZVtx),
       fID(part.fID),
       fEvtNumber(part.fEvtNumber),
       fUse(part.fUse),
       fChi2(part.fChi2),
       fIsSet(part.fIsSet) {
 }
 
 Tracks &Tracks::operator=(
     const Tracks &obj) {
   if (this == &obj) {
     return *this;
   }
   fIsReset = obj.fIsReset;
   fP = obj.fP;
   fIDTracks = obj.fIDTracks;
   fCharge = obj.fCharge;
   fInvMass = obj.fInvMass;
   fZVtx = obj.fZVtx,
   fID = obj.fID;
   fEvtNumber = obj.fEvtNumber;
   fUse = obj.fUse;
   fChi2 = obj.fChi2;
   fIsSet = obj.fIsSet;
   return (*this);
 }
 
 Tracks::~Tracks() {
   fP.clear();
   fIDTracks.clear();
   fCharge.clear();
 }

 
 void Tracks::SetTrack(region_particle *track) {
   this->Reset();
   fParticle = track;
   // we may need to check if the track isnt available at all? what happens in that case?
   fIsReset = false;
   if (fParticle) {
     //this->SetIDTracks(fParticle->GetID());
     this->SetTrackingInformation();
     this->SetEvtNumber(-999); /// we need to get a way to store event numbers
   } else {
     this->fIsSet = false;
   }
  }

 /// here we can set all the kinemtics of the particles
void Tracks::SetTrackingInformation() {
   //this->SetTheta(fParticle->getTheta()); // we need to see if this is required.. ask Yijie
  
   //this->SetCharge(fParticle->getParticle()->getCharge()); // somehow I did now see getter for the particle charge in region_particle class
   this->SetMomentum(0, fParticle->getPx(), fParticle->getPy(), fParticle->getPz());
   this->fChi2 = fParticle-> getChi2Pid();
 }

  float Tracks::GetBeta(region_particle*track) const {
   static float beta = fParticle->getBeta(); //we need find method for beta
   return beta;
 }
 


 void Tracks::Reset() {
   if (!fIsReset) {

     fChi2 = 0;
     GetMomentum(0).SetXYZ(0, 0, 0);
     fIDTracks.clear();
     fCharge.clear();
     //we don't want to reset the fPDGCode
     //we don't want to reset isMC
     fUse = false;
     fIsSet = true;
     fIsReset = true;
   }
 }