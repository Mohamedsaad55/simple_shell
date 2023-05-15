#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pidmax)
echo "Maximum p ID : $pidmax"
