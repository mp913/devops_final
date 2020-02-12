FROM gcc:latest as build

WORKDIR /build

# download packages
RUN apt-get update && \
    apt-get install -y \
#      libboost-dev libboost-program-options-dev \
#      libgtest-dev \
      cmake
#    && \
#    #cmake -DCMAKE_BUILD_TYPE=Release /usr/src/gtest && \
#    cmake --build . && \
#    mv lib*.a /usr/lib

# copy directory /src into container
ADD ./src /app/src

# build directory set up
WORKDIR /app/build

# project build
RUN cmake ../src && \
    cmake --build .

# run ---------------------------------------

# use ubuntu:latest
FROM ubuntu:latest

# add user
RUN groupadd -r sample && useradd -r -g sample sample
USER sample

# set up workdir
WORKDIR /app

# copy app into workdir
COPY --from=build /app/build/deanery_app .

# set up entry point
ENTRYPOINT ["./deanery_app"]