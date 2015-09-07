#include "~/click/elements"

elementclass MyUDPChecker{ input->CheckIPHeader() -> IPClassifier(udp,-) -> CheckUDPHeader -> [0]output}
dpimb :: DPIMB {input -> output}


FromDevice("eth0") -> MyUDPChecker;
MyUDPChecker[0] -> dpimb;
dpimb[0] -> ToDevice("eth0");