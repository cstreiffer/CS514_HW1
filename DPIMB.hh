#ifndef CLICK_DPIMB_HH
#define CLICK_DPIMB_HH
#include <click/element.hh>
#include <click/vector.hh>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
CLICK_DECLS

class DPIMB : public Element {
public:

  DPIMB() CLICK_COLD;

  const char *class_name() const	{ return "DPIMB"; }
  const char *port_count() const	{ return PORTS_1_1; }
  const char *processing() const	{ return PUSH; }
  void push(int port, Packet *p);
  // void add_handlers() CLICK_COLD;
  int initialize(ErrorHandler *); 

  bool check_blacklist(std::string url);

private:
	String input_file;
	String output_file;
  std::ifstream myInput;
  std::ofstream myOutput;
  int packet_counter;
  Vector<std::string> blacklist;
};

CLICK_ENDDECLS
#endif