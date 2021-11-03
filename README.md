<h1> Bazel Build with cpprestsdk.</h1>
 

Docker is used in this tiny project. See `Dockerfile` first.  

1. Install packages.
   
~~~
RUN apt-get update && apt-get upgrade

RUN apt-get install -y build-essential libboost-atomic-dev libboost-thread-dev libboost-system-dev libboost-date-time-dev libboost-regex-dev libboost-filesystem-dev libboost-random-dev libboost-chrono-dev libboost-serialization-dev libwebsocketpp-dev openssl libssl-dev cmake ninja-build git wget curl unzip libcpprest-dev
~~~


2. Install Bazel.

~~~
ARG BAZEL_VERSION=3.4.1

RUN mkdir /bazel && \
    wget --no-check-certificate -O /bazel/installer.sh "https://github.com/bazelbuild/bazel/releases/download/${BAZEL_VERSION}/b\
azel-${BAZEL_VERSION}-installer-linux-x86_64.sh" && \
    wget --no-check-certificate -O  /bazel/LICENSE.txt "https://raw.githubusercontent.com/bazelbuild/bazel/master/LICENSE" && \
    chmod +x /bazel/installer.sh && \
    /bazel/installer.sh  && \
    rm -f /bazel/installer.sh
~~~

3. Copy project files to docker image.

~~~
COPY WORKSPACE /WORKSPACE
COPY example.cpp /example.cpp
COPY BUILD /BUILD
~~~


4. Bazel build.  

~~~  
RUN bazel build //:debug
~~~

5. Run.  

~~~  
RUN bazel-bin/debug
~~~




