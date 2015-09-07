#include "~/click/elements"

elementclass MyUDPChecker{ input->CheckIPHeader() -> IPClassifier(udp,-) -> CheckUDPHeader -> [0]output}
dpimb :: DPIMB {input -> output}


FromDevice(MyUDPChecker, ENCAP IP);
udp[0] -> dpimb;
ToDevice(DPIMB, ENCAP IP);