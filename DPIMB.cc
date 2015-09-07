#include <click/config.h>
#include "DPIMB.hh"
CLICK_DECLS

DPIMB::DPIMB()
{
  _drops = 0;
}

int DPIMB::configure(Vector< String > & conf, ErrorHandler * errh)  
{

}

void
DPIMB::drop_it(Packet *p)
{
  if (_drops == 0)
    click_chatter("DPIMB: dropped a packet");
  _drops++;
  if (noutputs() == 2)
    output(1).push(p);
  else
    p->kill();
}

Packet *
DPIMB::simple_action(Packet *p)
{
  if (p->packet_type_anno() == Packet::BROADCAST || p->packet_type_anno() == Packet::MULTICAST) {
    drop_it(p);
    return 0;
  } else
    return p;
}

static String
DPIMB_read_drops(Element *f, void *)
{
  DPIMB *q = (DPIMB *)f;
  return String(q->drops());
}

void
DPIMB::add_handlers()
{
  add_read_handler("drops", DPIMB_read_drops, 0);
}

CLICK_ENDDECLS
EXPORT_ELEMENT(DPIMB)
ELEMENT_MT_SAFE(DPIMB)