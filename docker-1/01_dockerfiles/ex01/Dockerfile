# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mofikrat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 12:24:07 by mofikrat          #+#    #+#              #
#    Updated: 2019/07/30 12:44:42 by mofikrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:latest

MAINTAINER mofikrat <mofikrat@student.42.fr>


## 1-ENV VARIABLES##
####################
ENV VERSION=3.9.1
ENV	INSTALL_FOLDER=/home/teamspeak3

## 2- INSTALLING REQUIRED PACKAGES##
####################################
RUN apt-get update -y && apt-get install -y bzip2 wget
RUN wget https://files.teamspeak-services.com/releases/server/${VERSION}/teamspeak3-server_linux_amd64-${VERSION}.tar.bz2 
RUN tar jxf teamspeak3-server_linux_amd64-${VERSION}.tar.bz2 

RUN mkdir /home/teamspeak3
RUN mv /teamspeak3-server_linux_amd64 /home/teamspeak3/teamspeak3-server_linux_amd64
RUN cd /home/teamspeak3/teamspeak3-server_linux_amd64

## 3-CLEANING ##
################

RUN rm /teamspeak3-server_linux_amd64-${VERSION}.tar.bz2
RUN apt-get purge -y bzip2 wget

## 4-EXPOSING REQUIRED PORTS##
##############################
EXPOSE 41144 30033 10011 9987/udp

## 5-CHECKING LICENSE##
#######################
RUN cd /home/teamspeak3/teamspeak3-server_linux_amd64
ENV TS3SERVER_LICENSE=accept

## 6-LAUNCH START SCRIPT##
##########################
#ENTRYPOINT sh /home/teamspeak3/teamspeak3-server_linux_amd64/ts3server_startscript.sh start
ENTRYPOINT sh /home/teamspeak3/teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh
