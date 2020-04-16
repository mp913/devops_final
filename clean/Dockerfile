FROM gcc:latest as build

WORKDIR /app/build

RUN apt-get update && apt-get install -y libboost-dev libboost-program-options-dev cmake

# copy /src to container
ADD ./src /app/src

# set up workdir for build

# build
RUN	cmake ../src 
RUN     cmake --build .

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