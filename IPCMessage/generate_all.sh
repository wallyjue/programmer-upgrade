#!/bin/bash
cd qstream
./generate.sh
cd ..

cd sip
./generate.sh
cd ..

cd framework 
./generate.sh
cd ..

cd qstream_ack_to_sip
./generate.sh
cd ..

cd qstream_ack_to_fw
./generate.sh
cd ..
