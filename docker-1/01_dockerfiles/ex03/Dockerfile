# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mofikrat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 12:08:52 by mofikrat          #+#    #+#              #
#    Updated: 2019/07/30 12:10:54 by mofikrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM ubuntu:latest

MAINTAINER mofikrat <mofikrat@student.42.fr>

## 1-update and upgrade ##
##########################
RUN apt-get update && apt-get upgrade -y

## 2-installing required packages ##
####################################
RUN apt-get install -y ca-certificates openssh-server curl wget postfix tzdata vim

## 3-unpackaging gitlab-ce components ##
########################################
RUN wget https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh && chmod 777 script.deb.sh && ./script.deb.sh && apt-get install -y gitlab-ce

## 4-cleaning ##
################
RUN	apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

## 5-exposing ports ##
######################
EXPOSE 443 80 22

## 6-creating SSL folder ##
########################### 
RUN mkdir -p /etc/gitlab/ssl && chmod 700 /etc/gitlab/ssl && cd /etc/gitlab/ssl

## 7-generating a self-signed certificate for HTTPS ##
######################################################
RUN openssl req -nodes -new -newkey rsa:2048 -keyout /etc/gitlab/ssl/server.key -out /etc/gitlab/ssl/server.csr -subj "/C=FR/ST=Paris/L=Clichy/O=42/OU=DOCKER PROJECT by mofikrat"

RUN openssl x509 -req -days 365 -in /etc/gitlab/ssl/server.csr -signkey /etc/gitlab/ssl/server.key -out /etc/gitlab/ssl/server.crt

## 8-updating gitlab.rb with desired config ##
##############################################

RUN echo "nginx['enable'] = true" > /etc/gitlab/gitlab.rb
RUN echo "nginx['client_max_body_size'] = '250m'" >> /etc/gitlab/gitlab.rb
RUN echo "nginx['redirect_http_to_https'] = true" >> /etc/gitlab/gitlab.rb
RUN echo "nginx['redirect_http_to_https_port'] = 80" >> /etc/gitlab/gitlab.rb
RUN echo "nginx['ssl_certificate'] = \"/etc/gitlab/ssl/server.crt\"" >> /etc/gitlab/gitlab.rb
RUN echo "nginx['ssl_certificate_key'] = \"/etc/gitlab/ssl/server.key\"" >> /etc/gitlab/gitlab.rb
RUN echo "nginx['ssl_protocols'] = \"TLSv1.2\"" >> /etc/gitlab/gitlab.rb
RUN echo "external_url 'https://127.0.0.1'" >> /etc/gitlab/gitlab.rb
RUN echo "nginx['listen_https'] = true" >> /etc/gitlab/gitlab.rb
RUN echo "letsencrypt['enable'] = false" >> /etc/gitlab/gitlab.rb

## 9-initiating runsvdir + launching the reconfiguration + restarting all the services + monitoring nginx logs ## 
#################################################################################################################
ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && gitlab-ctl restart && gitlab-ctl tail nginx
