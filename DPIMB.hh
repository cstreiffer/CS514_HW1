#ifndef CLICK_DPIMB_HH
#define CLICK_DPIMB_HH
#include <click/element.hh>
#include <click/list.hh>
#include <click/config.h>
#include <iostream>
#include <string>
#include <sstream>

CLICK_DECLS

/*
 * =c
 * DropBroadcasts
 * =s annotations
 * drops link-level broadcast and multicast packets
 * =d
 * Drop packets that arrived as link-level broadcast or multicast.
 * Used to implement the requirement that IP routers not forward
 * link-level broadcasts.
 * Looks at the packet_type_anno annotation, which FromDevice sets.
 * =a FromDevice
 */

class DPIMB : public Element {
public:

  const char *class_name() const	{ return "DPIMB"; }
  const char *port_count() const	{ return PORTS_1_1; }
  const char *processing() const	{ return PUSH }
  int DPIMB::initialize(ErrorHandler *errh);	
  void DPIMB::add_handlers();

  bool check_blacklist(String url);
  Packet *simple_action(Packet *);

private:
	String input_file;
	String output_file;
	// List/vector of Strings
	//List<String> blacklist;
  int packet_counter;
};

CLICK_ENDDECLS
#endif