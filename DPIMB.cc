#include <click/config.h>
#include "DPIMB.hh"
CLICK_DECLS

DPIMB::DPIMB()
{
  input_file = "/root/hw1/blacklist.txt";
  output_file = "/root/hw1/logs.txt";
  packet_counter = 0;
  file_in = fopen(input_file, "r");
  file_out = fopen(output_file, "w");
}

int DPIMB::initialize(ErrorHandler *errh) 
{
  // Load the input file

  // Create Vector/List of Strings

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

}

Packet *
DPIMB::simple_action(Packet *p)
{
  // Extract DNS url from packet and sent to method check_blacklist
  String url = extract_dns(p);

  if(check_blacklist(url)) {
    p->kill();
    fputs(url, file_out);
    fputs("\n", file_out);
  } else {
    // forward the packet through the output port
  }
}

CLICK_ENDDECLS
EXPORT_ELEMENT(DPIMB)
ELEMENT_MT_SAFE(DPIMB)