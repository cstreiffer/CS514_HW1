#include <click/config.h>
#include "DPIMB.hh"
#include <click/glue.hh>
CLICK_DECLS

DPIMB::DPIMB()
{
  packet_counter = 0;

  myInput.open("/home/click/blacklist.txt");
  myOutput.open("/home/click/logs.txt");
}

int DPIMB::initialize(ErrorHandler *errh) 
{
  // Load the input file
  std::string line;
  if(myInput.is_open()) {
    while(getline(myInput, line)) {
      blacklist.push_back(line);
      click_chatter(line.c_str());
    }
    myInput.close();
  }

  return 0;
} 

bool
DPIMB::check_blacklist(std::string url)
{
  // Iterate through list, check against String url
  for (Vector<std::string>::const_iterator iterator = blacklist.begin(), end = blacklist.end(); iterator != end; ++iterator) {
    std::string black = *iterator;
    click_chatter(black.c_str());
    if(black.compare(url)==0){
        return 1;
    }
  }

  return 0;
}

void
DPIMB::push(int port, Packet *p)
{
  // Extract DNS url from packet and sent to method check_blacklist
  std::string url = "Round 2";

  if(!check_blacklist(url)) {
    myOutput << url << "\n";
    p->kill();

  } else {    
    // forward the packet through the output port
    output(0).push(p);
  }
}

CLICK_ENDDECLS
EXPORT_ELEMENT(DPIMB)
ELEMENT_MT_SAFE(DPIMB)