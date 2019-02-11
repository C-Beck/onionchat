# onionchat
## Usage
* ```onionchat -s``` to start as the server for a session
* ```onionchat``` to start as a client
* ```onionchat -h <ip>``` to start as a headless node connecting to ```<ip>```
## Configuration
Run ```onionconfig``` to create/modify a configuration file

Reads from ~/.config/onionchat/config, ~/.onionchat/config, or ~/.onionconfig to get configuration information
## Dependencies
1. ip
    1. This program uses the command ```ip route get 8.8.8.8``` to get the local ip of the machine requiring an active internet connection and the availability of the 8.8.8.8 dns server
1. head
1. cut
1. ncurses
1. openssl
    * Minimum Version
        1. 1.1.1a
        1. 1.1.0j
        1. 1.0.2q
## About
This project started with the thought that "building a onion-routed chat system shouldn't be *that* hard." Well here we are.

onionchat was built with the intention of being lighter-weight and quick
*-ish* . It uses rolling keys synced by the server along with the ip of the device to generate
a pseudorandom key using sha-512. This allows a unique key to be generated for each member of the network with mnimal data exchange and computation time. The rolling
key was added to minimize valid key duration in the case of a known plaintext attack. onionchat utilizes an xor cypher as a stream cypher and as the name suggests is
onion routed and also *mostly* decentralized.

The word "server" in the description of the ```-s``` flag may be misleading. This system does not use the traditional client-server architecture but instead nominates
the first device that joins to act as an organizer to syncronize the user list and rolling keys. The "server" also acts to initalize new members to the network with the
user list and the rolling keys. This "server" is able to migrate througout the network as devices enter and leave the network.

The rolling key system is designed to be reasonably robust to network and device latency since some of the devices may be lower powered devices based on ARM, CORE 2, or
similar. This is done by retaining the two most recent keys and verifying that the decryption has produced a header that matches a known format. Since the hash used for
the key changes significantly if the input is only one bit different, it is simple to check if the decrypted header is in the correct format rather than a garbled mess.
These checks are easy to implement reusing existing functions and provide simple and effective insurance incase a message is in transit when the key is changed.


