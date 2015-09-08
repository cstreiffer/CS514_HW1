#include <click/config.h>
#include "DPIMB.hh"
CLICK_DECLS

DPIMB::DPIMB()
{
  input_file = "/root/hw1/blacklist.txt";
  output_file = "/root/hw1/logs.txt";
  packet_counter = 0;
  std::ifstream in(input_file);
  std::ofstream out(output_file);
  //std::list<String> blacklist;

}

int DPIMB::initialize(ErrorHandler *errh) 
{
  // Load the input file

  // Create Vector/List of Strings
  return 0;
} 

bool
DPIMB::check_blacklist(String url)
{
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
  // Extract DNS url from packet and sent to method check_blacklist
  String url = extract_dns(p);

  if(check_blacklist(url)) {
    p->kill();
    std::cout << url << "\n";
  } else {
    // forward the packet through the output port
    output(0).push(p);
  }
}

String extract_dns(Packet *p) {
  return "hello";
}


CLICK_ENDDECLS
EXPORT_ELEMENT(DPIMB)
ELEMENT_MT_SAFE(DPIMB)