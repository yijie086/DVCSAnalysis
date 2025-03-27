#include "TrackCuts.h"
// Default constructor
TrackCuts::TrackCuts()
    : //fMCHists(nullptr), 
    fMinimalBooking(nullptr),
    fHists(nullptr), 
    fPmin(0.0), 
    fPmax(100.0),
    fcutPt(0),
     fVtXmin(-100.0), 
     fVtXmax(100.0),
     fVtYmin(-100.0), 
     fVtYmax(100.0), 
     fVtZmin(-100.0), 
     fVtZmax(100.0),  
     fCharge(0),
     fChiSquared(0),
     fcutPID(0){
      }

TrackCuts::TrackCuts(const TrackCuts &cuts)
    : //fMCHists(cuts.fMCHists), 
    fMinimalBooking(cuts.fMinimalBooking),
    fHists(cuts.fHists), 
    fpTmin(cuts.fpTmin),
    fpTmax(cuts.fpTmax), 
    fPmin(cuts.fPmin), 
    fPmax(cuts.fPmax),
    fcutPt(cuts.fcutPt),
    fcutPID(cuts.fcutPID),
    fCharge(cuts.fCharge),
    fChiSquared(cuts.fChiSquared){
    
 }

TrackCuts &TrackCuts::operator=(const TrackCuts &cuts) {
  if (this == &cuts) {
    return *this;
  }
  {
    //this->fMCHists = cuts.fMCHists;
    this->fMinimalBooking = cuts.fMinimalBooking;
    this->fHists = cuts.fHists;
    this->fpTmin = cuts.fpTmin;
    this->fpTmax = cuts.fpTmax;
    this->fPmin = cuts.fPmin;
    this->fPmax = cuts.fPmax;
    this->fcutPt = cuts.fcutPt;
    this->fcutPID = cuts.fcutPID;
    this->fChiSquared = cuts.fChiSquared;

  }
}

TrackCuts::~TrackCuts() {
 // if (fMCHists) {
   // delete fMCHists;
  //}
  if (fHists) {
    delete fHists;
   } else {
    if (!fMinimalBooking)
      fHists->FillTrackCounter(0);
  }
}

bool TrackCuts::isSelected(const clas12:: region_part_ptr &Track) {
  if (!Track) {
    std::cerr << "No Input Track received" << std::endl;
  }
  bool pass = true;
  if (pass) {
    if (!TrackingCuts(Track)) {
      pass = false;
    }
  }  
  if (pass && fcutPID) {
    if (!PIDCuts(Track)) {
      pass = false;
    } else {
      // we may wanna have some histograms related to cuts here
    }
    //Track->SetUse(pass); This is actaully important since we need to set the tract
  }
  return pass;
}

bool TrackCuts::TrackingCuts(const clas12::region_part_ptr &track) {
  bool pass = true;
  // detector track related cuts
  bool DetStatus = true; // should be accessed from the particle banks
  if (!DetStatus) {
    pass = false;
  } else {
  }
  if (pass && fcutPt) {
   // if (Track->GetPt() < fpTmin || Track->GetPt() > fpTmax) {
   ///   pass = false;
   // } else {
      // do something;
    }
  //}
  return pass;
}

bool TrackCuts::PIDCuts(const  clas12::region_part_ptr &track) {
  // We would need some detector response
  bool pass = true;

  // detector response check
  bool ECalisthere = false;
  bool HTCCisthere = false;

  if (pass) {
    float ChiSquared = 3.0; // needed from the track write a function here
    if (TMath::Abs(ChiSquared) > fChiSquared) {
      pass = false;
    } else {
      //if (!fMinimalBooking)
      //  fHists;
    }
  }
  return pass;
}

/// photon for study of DVCS or other events with dummy values
TrackCuts* TrackCuts::PhotonCuts() {
  TrackCuts *trackCuts = new TrackCuts();
  trackCuts->SetChargeCut(1);
  trackCuts->SetVtxX(-10,10);
  trackCuts->SetVtxY(-10,10); 
  trackCuts->SetVtxZ(-10,10);
  //trackCuts->SetPID();
  return trackCuts;
  }

/// electron for study of DVCS or other events with dummy values
TrackCuts* TrackCuts::ElectronCuts() {
  TrackCuts *trackCuts = new TrackCuts();
  trackCuts->SetChargeCut(1);
  trackCuts->SetVtxX(-10,10);
  trackCuts->SetVtxY(-10,10); 
  trackCuts->SetVtxZ(-10,10);
  return trackCuts;
  }

/// proton for study of DVCS or other events with dummy values
TrackCuts* TrackCuts:: ProtonCuts() {
TrackCuts *trackCuts = new TrackCuts();
trackCuts->SetChargeCut(1);
trackCuts->SetVtxX(-10,10);
trackCuts->SetVtxY(-10,10); 
trackCuts->SetVtxZ(-10,10);
return trackCuts;
}

//// booking histograms here 
void TrackCuts::BookQA(const clas12:: region_part_ptr &Track) {
  if (!fMinimalBooking) {

    // it might be usefull for us to create a class where we can store these variable already, 
    // thinking about the resuing these class after skimming and not sure if this would be possible
    // we should be able to figure out 

    float Px=Track->getPx();
    float Py=Track->getPy();
    float Pz=Track->getPz();

    /// we might need to store more variable separately but it seems there are already some defined in the clas12reader 

    float p = Track->getP();
    float Vz = Track->getVt();// not sure if its the correct one, check required
    float beta = Track->getBeta();// not sure if its the correct one, check required

    float phi = 0; //not sure if phi is required but lets keep might need for the fiducial cuts, need to find out how to compute
     

    for (int i = 0; i < 2; ++i) {
      //if (i == 0 || (i == 1 && Track->UseParticle())) {

        fHists->FillphiCut(i, phi);
        fHists->FillpCut(i, p);
        fHists->FillVzCut(i, p, Vz);
        //fHists->FillBeta(i, p, beta);
        // we may wanna include more histograms here
  
     // }
    }
  } else {
   // if (Track->UseParticle())
      fHists->FillpCut(1, Track->getP());
 // }
  return;
}
}

// Momentum cut
bool TrackCuts::PassesMomentumCut(
    const std::shared_ptr<clas12::particle> &track) const {
  float p = track->getP();
  return (p >= fPmin && p <= fPmax);
}

// Vertex Z position cut
bool TrackCuts::PassesVertexCut(
    const std::shared_ptr<clas12::particle> &track) const {
  return (track->getVz() >=fVtZmin && track->getVz() <=fVtZmax);
}

// PID cut
bool TrackCuts::PassesPIDCut(
    const std::shared_ptr<clas12::particle> &track) const {
  return (track->getPid() == fPID);
}

// Charge cut
bool TrackCuts::PassesChargeCut(
    const std::shared_ptr<clas12::particle> &track) const {
  return (track->getCharge()== fCharge);
}
