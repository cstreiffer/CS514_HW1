FromCapDump(browsing.pcap) -> r::IPClassifier(udp,-) 
r[0] -> CheckUDPHeader -> MyUDPChecker -> DPIMB-> ToDump(test.dump);

