#!/usr/bin/env bash
cp BUILD/Debug/*.bin /Volumes/MBED
if [[ $? -eq 0 ]]; then
    echo 'Success'
else
    echo 'Failed'
fi