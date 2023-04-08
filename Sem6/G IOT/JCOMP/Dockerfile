FROM python:3.11.2
COPY . /app
WORKDIR /app
RUN apt update && \
    apt install --no-install-recommends -y gcc && \
    apt clean && rm -rf /var/lib/apt/lists/*

RUN apt-get install libgl1 python3-opencv libsm6 libxext6 -y
RUN wget https://github.com/Kitware/CMake/releases/download/v3.24.2/cmake-3.24.2.tar.gz && \
    tar -zxvf cmake-3.24.2.tar.gz && \
    cd cmake-3.24.2 && \
    ./bootstrap && \
    make && \
    make install && \
    cmake --version && \
    cd .. && \
    rm -rf cmake-3.24.2 && \
    rm cmake-3.24.2.tar.gz

RUN pip install -r requirements.txt
CMD python main.py
# CMD cat /etc/os-release