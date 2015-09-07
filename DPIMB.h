#ifndef CLICK_DPIMB_HH
#define CLICK_DPIMB_HH
#include <click/element.hh>
#include <click/list.hh>
#include <click/string.hh>

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
  int DPIMB::initialize();	
  void DPIMB::add_handlers();

  void drop_it(Packet *);
  Packet *simple_action(Packet *);

private:
	list<string> dns_list;	
};

CLICK_ENDDECLS
#endif