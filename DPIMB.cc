#include <click/config.h>
#include "DPIMB.hh"
CLICK_DECLS

DPIMB::DPIMB()
{
  click_chatter("constructor\n");
  packet_counter = 0;

  myInput.open("/root/hw1/blacklist.txt");
  myOutput.open("/root/hw1/logs.txt");
  //std::list<String> blacklist;

}

int DPIMB::initialize(ErrorHandler *errh) 
{
  // Load the input file
  click_chatter("initialize\n");

  // Create Vector/List of Strings
  return 0;
} 

bool
DPIMB::check_blacklist(String url)
{
  click_chatter("check_blacklist\n");
  if(packet_counter==0){
    packet_counter=1;
    return 0;
  }
  else{
    packet_counter=0;
    return 1;
  }

  // Iterate through list, check against String url
  // for (std::list<int>::const_iterator iterator = blacklist.begin(), end = blacklist.end(); iterator != end; ++iterator) {
  //  String black = (String) *iterator;
  //  if(black.compare(url)==0){
        // return 1;
    //}
  //  std::cout << *iterator;}return 0;
// 


}

Packet *
DPIMB::simple_action(Packet *p)
{
  click_chatter("simple_action\n");
  // Extract DNS url from packet and sent to method check_blacklist
  String url = "Hello";

  if(check_blacklist(url)) {
    p->kill();
    myOutput << url << "\n";
  } else {
    // forward the packet through the output port
    output(0).push(p);
  }
}

CLICK_ENDDECLS
EXPORT_ELEMENT(DPIMB)
ELEMENT_MT_SAFE(DPIMB)