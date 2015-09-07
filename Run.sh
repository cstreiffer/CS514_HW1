elementclass MyUDPChecker{ input->CheckIPHeader() -> IPClassifier(udp,-) -> CheckUDPHeader -> [0]output}
dpimb :: DPIMB {input -> output}


FromDump(MyUDPChecker, ENCAP IP);
udp[0] -> dpimb;
ToDump(DPIMB, ENCAP IP);