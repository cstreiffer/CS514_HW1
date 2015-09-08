#include <click/config.h>
#include "DPIMB.hh"
#include <click/glue.hh>
#include <click/ipaddress.hh>
#include <clicknet/udp.h>
#include <clicknet/ip.h>
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
  std::string url = "www.google.com/help";

  const click_ip *iph = p->ip_header();
  const click_udp *udph = p->udp_header();

  uint16_t dest_port = (uint16_t) ntohs(udph->uh_dport);
  uint16_t source_port = (uint16_t) ntohs(udph->uh_sport);
  IPAddress source_port(iph->ip_src);

  std::cout << "The source port is: " << source_port.unparse() << "\n";

  if(dest_port == 53) {
    std::cout << "Within the loop correctly \n\n";
    if(check_blacklist(url)) {
      myOutput << url << " " << source_ip << "\n";
      p->kill();
    } else {    
      // forward the packet through the output port
      output(0).push(p);
    }
  }
}

CLICK_ENDDECLS
EXPORT_ELEMENT(DPIMB)
ELEMENT_MT_SAFE(DPIMB)