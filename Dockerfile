FROM ubuntu:16.04
MAINTAINER Lisheng Guan<guanlisheng@gmail.com>

RUN apt-get update && apt-get install -y build-essential git libgtk-3-dev libwebkitgtk-dev libwxgtk3.0-dev libwxgtk-webview3.0-dev

# copy wxsqliteplus source code to the container:
ADD . /wxsqliteplus

# Define working directory:
WORKDIR /wxsqliteplus
