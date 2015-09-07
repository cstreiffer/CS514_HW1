#include <click/config.h>
#include "DPIMB.hh"
CLICK_DECLS

DPIMB::DPIMB()
{
  input_file = "/root/hw1/blacklist.txt";
  output_file = "/root/hw1/logs.txt";
}

int DPIMB::initialize(ErrorHandler *errh) 
{
  // Load the input file

  // Create Vector/List of Strings

} 

bool
DPIMB::check_blacklist(String url)
{
  // Iterate through list, check against String url

}

Packet *
DPIMB::simple_action(Packet *p)
{
  // Extract DNS url from packet and sent to method check_blacklist
  String url = extract_dns(p);

  if(check_blacklist(url)) {
    // Delete the file and log it
  } else {
    // forward the packet through the output port
  }
}

CLICK_ENDDECLS
EXPORT_ELEMENT(DPIMB)
ELEMENT_MT_SAFE(DPIMB)