elementclass MyUDPChecker{ input->CheckIPHeader() -> IPClassifier(udp,-) -> CheckUDPHeader -> [0]output}

FromDevice("eth0") -> MyUDPChecker -> DPIMB-> ToDevice("eth0");