#include "DVCSAnalysis.h"

DVCSAnalysis::DVCSAnalysis()
    : fisLightWeight(false), 
    fIsMC(false), 
    fEvent(nullptr),
    fEventCuts(nullptr),
    fTrackCutsPhoton(nullptr),
    fTrackCutsElectron(nullptr),
    fTrackCutsProton(nullptr){
  std::cout << "Performing DVCSAnalysis Yey!" << std::endl;
}

DVCSAnalysis::DVCSAnalysis( bool isMC)
    : fisLightWeight(false), fIsMC(isMC),
      fEvent(nullptr),
      fEventCuts(nullptr),    
      fTrackCutsPhoton(nullptr),
      fTrackCutsElectron(nullptr),
      fTrackCutsProton(nullptr) {}

DVCSAnalysis::~DVCSAnalysis() { // Destructor (clean up if necessary)
  delete fEvent;
  delete fTrackCutsPhoton;
  delete fTrackCutsElectron;
  delete fTrackCutsProton;
  // delete fTrack;
}

void DVCSAnalysis::UserCreateOutputObjects() {

  if (!fEventCuts) {
    std::cerr << "No Event cuts." << std::endl;
  } else {
    fHistMomentum = new TH1F("fHistMomentum", "Momentum Distribution", 100, 0, 10);

    // Create TTree for event data
    fTree = new TTree("EventTree", "DVCS Event Data");
    fTree->Branch("Momentum", &fMomentum, "Momentum/F");
    
    if (fTaskManager) {
      fTaskManager->AddHistogram("HistList", fHistMomentum);  // Add histogram to list
      fTaskManager->AddTree("EventTree", fTree);  // Add tree to output
  } else {
      std::cerr << "Error: Task manager is not set!" << std::endl;
  }
  }
}

void DVCSAnalysis::UserExec(Event &event) {
  if (!event.isValid()) {
    std::cerr << "No events lol." << std::endl;
  } else {
    for (const auto &particle : event.getDetParticles()) {
      
      fTrack->SetTrack(particle); // is where we set tracks and get possible track properties;

      // here we can ask if the particle is of our interest based on the track cuts we have defined
      if (fTrackCutsPhoton->isSelected(particle)) {
        std::cout << "Its a photon" << std::endl;
      }
      if (fTrackCutsElectron->isSelected(particle)) {
        std::cout << "Its an electron" << std::endl;
      }
      if (fTrackCutsProton->isSelected(particle)) {
        std::cout << "Its a proton" << std::endl;
      }
            
      // particle.print();
    }
  }
}

// we may use some examples like this
void DVCSAnalysis::FillTree() {
  if (fTree) {
      fTree->Fill();  // Store the current momentum into the tree
  }
}

void DVCSAnalysis::FillHistogram() {
  if (fHistMomentum) {
      fHistMomentum->Fill(fMomentum);  // Fill histogram with the momentum
  }
}