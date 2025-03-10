#ifndef EVENT_CUTS_H
#define EVENT_CUTS_H

class EventCuts {
public:
    EventCuts(double threshold);
    bool passesCut(double value) const;
    void setDirToHIPO(string dataPath){
        if(dataPath==""){
            cout<<"\nNeed data file"<<endl;
            cout<<"Analysis script terminated due to no valid path to Hipo files\n"<<endl;
            exit(0);
          }
        mDataPath=dataPath;
    };
    string GetDataPath(){
    return mDataPath;
    }

private:
    double threshold;
    string mDataPath;

};

#endif // EVENT_CUTS_H
