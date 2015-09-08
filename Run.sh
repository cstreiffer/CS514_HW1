FromDump(browsing.pcap, STOP true, FORCE_IP true) -> r::IPClassifier(udp,-);
r[0] -> IPPrint(PAYLOAD ASCII) -> ToDump(test.pcap);
r[1] -> ToDump(temp.pcap);