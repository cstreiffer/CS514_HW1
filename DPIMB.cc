#include <click/config.h>
#include "DPIMB.hh"
#include <click/glue.hh>
CLICK_DECLS

DPIMB::DPIMB()
{
  click_chatter("constructor\n");
  packet_counter = 0;

  myInput.open("~/blacklist.txt");
  myOutput.open("~/logs.txt");
}

int DPIMB::initialize(ErrorHandler *errh) 
{
  click_chatter("initialize\n");
  // Load the input file
  std::string line;
  if(myInput.is_open()) {
    click_chatter("initialize-2\n");
    while(getline(myInput, line)) {
      blacklist.push_back(line);
      click_chatter("Making things\n");
    }
    myInput.close();
  }
  // Create Vector/List of Strings
  return 0;
} 

bool
DPIMB::check_blacklist(String url)
{
  return 1;

  // Iterate through list, check against String url
  // for (std::list<int>::const_iterator iterator = blacklist.begin(), end = blacklist.end(); iterator != end; ++iterator) {
  //  String black = (String) *iterator;
  //  if(black.compare(url)==0){
        // return 1;
    //}
  //  std::cout << *iterator;}return 0;
// 


}

void
DPIMB::push(int port, Packet *p)
{
  // Extract DNS url from packet and sent to method check_blacklist
  String url = "Hello";

  if(check_blacklist(url)) {
    click_chatter("Writing stuff\n");
    myOutput << url << "\n";
    p->kill();

  } else {    
    click_chatter("Pushing stuff\n");
    // forward the packet through the output port
    output(0).push(p);
  }
}

// 

CLICK_ENDDECLS
EXPORT_ELEMENT(DPIMB)
ELEMENT_MT_SAFE(DPIMB)