#!/bin/bash
cd ../
docker rmi -f school21/miniverter:1.0 && \
docker build . -t school21/miniverter:1.0 -f build/Dockerfile && \
docker run --rm  -it school21/miniverter:1.0

