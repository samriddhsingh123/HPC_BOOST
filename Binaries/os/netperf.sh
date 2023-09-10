#!/bin/bash

netserver

# Set the default server IP address to 127.0.0.1
default_server_ip="127.0.0.1"

# Check if the server IP address is provided as an argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 [server_ip]"
    echo "Using default IP address: $default_server_ip"
    server_ip="$default_server_ip"
else
    # Store the server IP address provided as an argument
    server_ip="$1"
fi

# Run netperf with TCP_STREAM test
netperf -H "$server_ip" -t TCP_STREAM
