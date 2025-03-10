#include "TrackCuts.h"

// Default constructor
TrackCuts::TrackCuts()
    : //fMCHists(nullptr), 
    //fHists(nullptr), 
    fPmin(0.0), 
    fPmax(100.0),
    fcutPt(0),
     fVtZmin(-100.0), 
     fVtZmax(100.0), 
      fCharge(0) {

      }

TrackCuts::TrackCuts(const TrackCuts &cuts)
    : //fMCHists(cuts.fMCHists), 
    //fHists(cuts.fHists), 
    fpTmin(cuts.fpTmin),
    fpTmax(cuts.fpTmax), 
    fPmin(cuts.fPmin), 
    fPmax(cuts.fPmax),
    fcutPt(cuts.fcutPt),
    fCharge(0) {
    
      }

TrackCuts &TrackCuts::operator=(const TrackCuts &cuts) {
  if (this == &cuts) {
    return *this;
  }
  {
    //this->fMCHists = cuts.fMCHists;
    //this->fHists = cuts.fHists;
    this->fpTmin = cuts.fpTmin;
    this->fpTmax = cuts.fpTmax;
    this->fPmin = cuts.fPmin;
    this->fPmax = cuts.fPmax;
    this->fcutPt = cuts.fcutPt;
  }
}

TrackCuts::~TrackCuts() {
 // if (fMCHists) {
   // delete fMCHists;
  //}
 // if (fHists) {
 //   delete fHists;
  //}
}

bool TrackCuts::isSelected(const std::shared_ptr<clas12::particle> &Track) {
  if (!Track) {
    std::cerr << "No Input Track received" << std::endl;
  }
  bool pass = true;
  if (pass) {
    if (!TrackingCuts(Track)) {
      pass = false;
    }
  }
  return pass;
}

bool TrackCuts::TrackingCuts(const std::shared_ptr<clas12::particle> &Track) {
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

bool TrackCuts::PIDCuts(const std::shared_ptr<clas12::particle> &Track) {
  bool pass = true;
  return pass;
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
