#!/bin/bash
echo "Making Random Password"
sudo < /dev/urandom tr -dc A-Za-z0-9 | head -c14; echo
echo "Created Password"
