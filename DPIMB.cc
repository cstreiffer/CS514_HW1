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
  // char * start = (char *) p->data();
  // char * end =  (char *) p->end_data();

  // char * i;
  // for(i=start; i < end; i++) {
  //   std::cout << (std::string) i << '\n';
  // }

  uint32_t udp_port = p->anno_u32(9);

  std::printf("The value of s is: %n\n", udp_port);


  std::string url = "temp";
  std::string ip = "temp2";

  if(check_blacklist(url)) {
    myOutput << url << " " << ip << "\n";
    p->kill();
  } else {    
    // forward the packet through the output port
    output(0).push(p);
  }
}

CLICK_ENDDECLS
EXPORT_ELEMENT(DPIMB)
ELEMENT_MT_SAFE(DPIMB)