#ifndef CLICK_DPIMB_HH
#define CLICK_DPIMB_HH
#include <click/element.hh>
#include <iostream>
#include <fstream>
CLICK_DECLS

class DPIMB : public Element {
public:

  DPIMB();

  const char *class_name() const	{ return "DPIMB"; }
  const char *port_count() const	{ return PORTS_1_1; }
  const char *processing() const	{ return PUSH; }
  int initialize(ErrorHandler *errh);	
  String extract_dns(Packet *p);
  bool check_blacklist(String url);
  Packet *simple_action(Packet *p);

private:
	String input_file;
	String output_file;
  std::ifstream myInput;
  std::ofstream myOutput;
  int packet_counter;
};

CLICK_ENDDECLS
#endif