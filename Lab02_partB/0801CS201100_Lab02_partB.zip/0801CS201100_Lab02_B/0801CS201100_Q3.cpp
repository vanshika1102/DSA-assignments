#include <iostream>
#include <list>
#include <queue>
#include <math.h>
#include <string.h>
using namespace std ;

int nop = 50 ; // number of processes
float CPUBoundProcessPercent = 0.03 ;
int cpuTimeFrame = 5 ;
int ct = 1 ; // ct is current time in simulation
int dur = 1 ; // duration of each simulation step
int conCntC = 0 ;
int conCntI=0 ;

class Process {
public:
int cpuTime, ioTime; // total cou and io time required
int   processType; // : IOBound = 2, CPUBound=1
int status ; // 0 - in process; 1 - completed
int   endTime;
int   waitTime;
int   consumedCpuTime;
int   consumedIOTime;
int currentSlotTime;
int   currentSlotRemainingTime;
int   currentSlotType; // io 2 ; cpu 1
int procID ;
void generateNextSlot() {
    // update consumed time
 if (currentSlotType == 2)  { consumedIOTime += currentSlotTime ;}
    else {  consumedCpuTime += currentSlotTime ;};
   // return if execution is completed
    if (consumedCpuTime + consumedIOTime >= cpuTime + ioTime) {
          //  if (procID < 2) cout << " ** Gets completed " << procID << endl ;
                 status = 1; // completed
                 return ;
    };
    // decide next slot type ;
    if (currentSlotType == 1) { currentSlotType = 2;
                                // if io for this process is complete, then switch back to cpu
                                if (consumedIOTime >= ioTime) currentSlotType =1;
                               }
        else                  { currentSlotType =1;
                                // if cpu for this process is complete, then switch back to io
                                if (consumedCpuTime >= cpuTime) currentSlotType = 2;
                              };
// determine next slot duration;
//looking percent to be between 2 to 20 %, but more likelyhood for 2 to 5 percent;
// rand value is multiplied y 10, to increase range; later divided by 10
    int x = rand() % 100 ;
    if ( x < 75) { x = rand()%30 + 20 ; // random number between 2 to 5
                 }
         else    { x = rand()%150 + 50 ; };
    if (currentSlotType == 1 ) {     currentSlotTime = 1.0 * x / 10.0 * cpuTime ;
                                      // if this value is larger than total cpu time remaining
                                     if ( currentSlotTime >= (cpuTime - consumedCpuTime)) currentSlotTime = (cpuTime - consumedCpuTime) ;
                               }
         else                  {     currentSlotTime = 1.0 * x / 10.0 * ioTime ;
                                      // if this value is larger than total io time remaining
                                     if ( currentSlotTime >= (ioTime - consumedIOTime)) currentSlotTime = (ioTime - consumedIOTime) ;
                               };
    currentSlotRemainingTime = currentSlotTime ;


} ; // end of generateNextSlot
} ; // end of Process class

class CPUHandler {
protected:
    list<Process *> procList ;

public:
 Process * getFreeProcess () { // returns a Process that no more needs CPU for its current slot
            Process * p = procList.front();
            if (p == NULL) return p ;
           if ( p->currentSlotRemainingTime <= 0 ){
                    procList.pop_front();
                    return p ;
               };
            return NULL  ;


 };
 void addProcess(Process *p){ // user can give a new process to CPU Handler for cpu needs
     procList.push_back(p);

 };

  Process * getIO()
  {
    Process *p =procList.front();
    if(p!=NULL)
    {

      std::list<Process *>::iterator it,temp=procList.begin();
      for (it = procList.begin(); it != procList.end(); ++it) 
      {
        if((*it)->processType==2){
          p= *it;
          temp=it;
          break;
        }
      }   
    procList.erase(temp);
    procList.push_front(p);
    }
    return(p);
 }

 void consume(int t){// consume a time slot of t time
     // choose a process, if not already selected

     // give t time to that process

     // if its currentSlot is complete, mark so
     //cout << "in ch consume" ;

     Process *p = getIO();
     if (p != NULL) {
             conCntC++;
         p->currentSlotRemainingTime -= t ;
         //if (p->procID < 1)  cout << "CPU "<< ct << "  id:" << p->procID << "slot remaining time : " << p->currentSlotRemainingTime<< endl ;
/*
        if (ct % cpuTimeFrame == 0 ){
                procList.pop_front();
               procList.push_back(p);
         }; */
     };

 }
};

class IOHandler {
protected:
list<Process *> procList ;

public:
Process * getFreeProcess () { // returns a Process that no more needs io for its current slot
                              // and removes that process from list here
    for (std::list<Process *>::iterator it = procList.begin(); it != procList.end(); ++it) {
            if  ((*it)->currentSlotRemainingTime <= 0) {
                //(*it)->consumedIOTime += (*it)->currentSlotTime ;
                procList.erase(it);
                return (*it);

            };

 //cout << *it << "  ";
     }; // end of for


 return NULL ;

 };
void addProcess(Process *p){ // user can give a new process to IO Handler for io needs
    procList.push_back(p);

 };
 void consume(int t){// consume a time slot of t time

     // to every process in list, add t time
      conCntI++;
     for (std::list<Process *>::iterator it = procList.begin(); it != procList.end(); ++it) {
             (*it)->currentSlotRemainingTime -= t ;

 //cout << *it << "  ";
     }; // end of for

 };


};

list<Process *> CompletedProcList ;

CPUHandler ch ;
IOHandler  ih ;

void createProcessList() {  // create process list, and add every process to either io list or cpu list


for (int i = 0 ; i < nop ; i++){
// creating single process
  Process *p = new Process ();
    // determine processType
    int x = rand() % 1000 ;
    p->processType = 2;
    if ( x < 1000 * CPUBoundProcessPercent) { p->processType = 1;
      // this process is CPU Bound;
    };

    // determine duration
    x=rand() % 10000+100  ; // upto 1100 ms

    if ( p->processType == 1) {
    p->cpuTime = x * 0.8 ;
    p->ioTime = x * 0.2 ;
    }
    else {
            p->cpuTime = x * 0.2 ;
            p->ioTime = x * 0.8 ;
    };
    int y = rand() * 100 ;
    p->currentSlotType = 2 ;
    if ( y < 50 )  p->currentSlotType = 1 ;
    p->generateNextSlot();

    // now add this to correct list
    if (p->currentSlotType == 1) { ch.addProcess(p);}
        else                     { ih.addProcess(p);};


    // initialise other variables
    p->status = 0 ;
    p->endTime = -1;
    p->waitTime = 0 ;
    p->consumedCpuTime = 0 ;
    p->consumedIOTime = 0 ;
   // p->currentSlotTime = 0 ;
    p->procID = i ;

}; // end of for loop

} // end of create process list

int main() {
    // first create process list
    createProcessList();

    // now run simulation loop


    while (CompletedProcList.size() < nop ) {
           // cout << "(" << CompletedProcList.size() <<")" ;

             ih.consume(dur);
             ch.consume(dur);

             Process * p ;
             while ((p = ih.getFreeProcess()) != NULL ){
                cout << "+" ;
                p->generateNextSlot();
                if (p->status == 0 ) {ch.addProcess(p);}
                    else             { p->endTime=ct ;  CompletedProcList.push_back(p);};
             };
             while ((p = ch.getFreeProcess()) != NULL ){
                    cout << "-" ;

                p->generateNextSlot();
               if (p->status == 0 ) {ih.addProcess(p);}
                    else             { p->endTime=ct ; CompletedProcList.push_back(p);};
             }


    ct = ct + dur ;
    } // end of while

     cout << endl << "cpuTime " << " "
                 <<"ioTime " << " "
                 <<"processType  "<< " "
                 <<"status  "<< " "
                 <<"consumedCpuTime  "<< " "
                 << "consumedIOTime " << " "
                  << endl ;
     int totalCpu = 0 , totalIO = 0 ;
    for (std::list<Process *>::iterator it = CompletedProcList.begin(); it != CompletedProcList.end(); ++it) {
            totalCpu += (*it)->cpuTime ;
            totalIO  +=  (*it)->ioTime  ;
            cout << (*it)->cpuTime  << " "
                 <<(*it)->ioTime  << " "
                 <<(*it)->endTime  << " "
                 <<(*it)->processType  << " "
                 <<(*it)->status  << " "
                 <<(*it)->consumedCpuTime  << " "
                 << (*it)->consumedIOTime  << " "
                  << (*it)->procID  << " "
                  << endl ;




    }

    cout << "Total CPU :" << totalCpu << endl ;
    cout << "Total IO " << totalIO << endl ;
    cout << "Last time : " << ct << endl ;
    cout << " CPU consume count " <<  conCntC << endl ;
     cout << " IO consume count " <<  conCntI << endl ;




}