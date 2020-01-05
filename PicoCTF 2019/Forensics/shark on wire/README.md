# shark on wire 1

Wireshark filter: `udp.stream eq 6`

Flag: `picoCTF{StaT31355_636f6e6e}`

# shark on wire 2

Wireshark filter: `frame.number >= 1106 and frame.number <=1301 and udp and !(mdns) and ip.src==10.0.0.66`

Create a list of all `src ports` modulo 5000 and convert to ASCII.

Flag: `picoCTF{p1LLf3r3d_data_v1a_st3g0}`