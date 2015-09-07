#ifndef CLICK_DPIMB_HH
#define CLICK_DPIMB_HH
#include <click/element.hh>
#include <click/atomic.hh>
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

  DropBroadcasts() CLICK_COLD;

  const char *class_name() const	{ return "DPIMB"; }
  const char *port_count() const	{ return PORTS_1_1; }
  const char *processing() const	{ return PROCESSING_A_AH; }
  void add_handlers() CLICK_COLD;

  int Element::configure	(Vector< String > & conf, ErrorHandler * errh)	

  uint32_t drops() const		{ return _drops; }

  void drop_it(Packet *);
  Packet *simple_action(Packet *);

private:
  atomic_uint32_t _drops;
};

CLICK_ENDDECLS
#endif