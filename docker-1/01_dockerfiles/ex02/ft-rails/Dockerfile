# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mofikrat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 12:18:51 by mofikrat          #+#    #+#              #
#    Updated: 2019/07/30 12:23:29 by mofikrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM ruby

## 1-update ##
##############
RUN apt-get update -y && apt-get upgrade -y 


## 2-install required framework packages ##
###########################################

##WEBSERVER TECHNOLOGY############
RUN apt-get install -y nodejs
##       RAILS       #############
RUN apt-get install -y rails
###### PREPARE APP FOLDER ########
RUN mkdir -p /opt/app


## 3-COPY REQUIRED DEP/GEMS in /opt/app##
#########################################

#ONBUILD COPY app /opt/app
#ONBUILD WORKDIR /opt/app
ONBUILD WORKDIR /opt/app
ONBUILD ADD . /opt/app

## 4-expose port 3000 ##
########################
ONBUILD EXPOSE 3000

## 5-UPDATE THE RACK  in case Gemfile has version not aligned with the installed versions##
###########################################################################################
ONBUILD RUN bundle update rake

## 6-INSTALL GEMS+MIGRATE/POPULATE DB##
#######################################
ONBUILD RUN bundle install
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:seed
