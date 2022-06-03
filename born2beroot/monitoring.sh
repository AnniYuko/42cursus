#!/bin/bash

wall "
	#Architecture: $(uname -a)
	#CPU physical: $(lscpu --parse=core,socket | grep -v '^#' | awk -F, '{print $1*$2}')
	#vCPU: $(grep processor /proc/cpuinfo | wc -l)
	#Memory usage (RAM): $(free --human | awk '/^Mem/ {printf "%s/%s (%.2f %%)", $3, $2, $3/$2*100}')
	#Disk usage: $(df --human-readable / /var /srv /home /tmp /var/log --total | awk '/^total/ {printf "%s/%s (%.2f %%)", $3,$2,$3/$2*100}')
	#CPU load (utilization rate of processors): $(top -bn1 | awk '/Cpu/ {printf "%.1f %%", $2}')
	#Last boot: $(who --boot | awk '{print $3,$4}')
	#LVM active: $(lsblk -o type | grep lvm | sort -u | awk '{if ($1) {print "yes"} else {print "no"}}')
	#Active connections (TCP): $(awk 'BEGIN{ORS=" "} /^Tcp/ {print $10}' /proc/net/snmp)
	#User log: $(who | cut -d ' ' -f 1 | sort -u | wc -l)
	#Network: private IP: $(hostname -I) (MAC address: $(ip link | grep ether | awk '{print $2}'))
	#Number of commands executed with sudo: $(cat /var/log/sudo/sudo.log | wc -l)
"
