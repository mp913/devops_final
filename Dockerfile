FROM gcc:latest as build

WORKDIR /gtest_build

RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      libgtest-dev \
      cmake \
    && \
    cmake -DCMAKE_BUILD_TYPE=Release /usr/src/gtest && \
    cmake --build . && \
    mv lib*.a /usr/lib

# copy /src to container
ADD ./src /app/src

# set up workdir for build
WORKDIR /app/build

# build and test
RUN cmake ../src && \
    cmake --build . && \
    CTEST_OUTPUT_ON_FAILURE=TRUE cmake --build . --target test

FROM ubuntu:latest

# add user due safety reasons
RUN groupadd -r sample && useradd -r -g sample sample
USER sample

# set up workdir
WORKDIR /app

# copy app to workdir
COPY --from=build /app/build/cpp_calculator_app .

# Set up entry point
ENTRYPOINT ["./cpp_calculator_app"]