# onionchat
## Usage
* ```onionchat -s``` to start as the server for a session
* ```onionchat``` to start as a client
* ```onionchat -h <ip>``` to start as a headless node
## Configuration
Run ```onionconfig``` to create/modify a configuration file

Reads from ~.config/onionchat/config, ~/.onionchat/config, or ~/.onionconfig to get configuration information
## Dependencies
1. ip
    1. This program uses the command ```ip route get 8.8.8.8``` to get the local ip of the machine requiring an active internet connection and the availability of the 8.8.8.8 dns server
1. head
1. cut
1. ncurses
