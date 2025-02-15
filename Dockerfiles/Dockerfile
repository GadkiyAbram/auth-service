FROM gcc:latest

RUN apt-get update && \
    apt-get install -y software-properties-common && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get update && \
    apt-get install -y libpq-dev libpqxx-dev postgresql-client \
    wget \
    gnupg \
    cmake \
    libssl-dev && \
    wget -qO- "https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/boost_1_81_0.tar.gz" | tar -xz -C /usr/local && \
        cd /usr/local/boost_1_81_0 && \
        ./bootstrap.sh && \
        ./b2 install && \
        apt-get clean && \
        rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/trusch/libbcrypt.git /tmp/libbcrypt && \
    cd /tmp/libbcrypt && \
    mkdir build && cd build && \
    cmake .. && make && make install && \
    rm -rf /tmp/libbcrypt

RUN git clone https://github.com/Thalhammer/jwt-cpp.git /tmp/jwt-cpp && \
    cd /tmp/jwt-cpp && \
    mkdir build && cd build && \
    cmake .. && make && make install && \
    rm -rf /tmp/jwt-cpp

RUN wget -qO- "https://github.com/Kitware/CMake/releases/download/v3.28.2/cmake-3.28.2-linux-x86_64.tar.gz" | tar --strip-components=1 -xz -C /usr/local

RUN mkdir -p /usr/local/include/nlohmann && \
    wget -O /usr/local/include/nlohmann/json.hpp https://github.com/nlohmann/json/releases/latest/download/json.hpp

RUN git clone https://github.com/laserpants/dotenv-cpp.git /tmp/dotenv && \
    cd /tmp/dotenv && \
    mkdir -p build && \
    cd build && \
    cmake .. && \
    make && \
    make install && \
    rm -rf /tmp/dotenv

WORKDIR /usr/src/auth-service

COPY . .

CMD ["bash", "-c", "cmake . && make && ./auth-service"]