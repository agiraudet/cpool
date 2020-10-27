#!/bin/sh

ifconfig -a | grep ether | cut -c 8- | tr -d ' '
