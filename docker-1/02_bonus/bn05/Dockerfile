# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mofikrat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 23:01:03 by mofikrat          #+#    #+#              #
#    Updated: 2019/07/30 23:01:06 by mofikrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM ubuntu:latest

RUN \
  apt-get update && \
  apt-get install -y nginx && \
  rm -rf /var/lib/apt/lists/* && \
  echo "\ndaemon off;" >> /etc/nginx/nginx.conf && \
  chown -R www-data:www-data /var/lib/nginx

COPY web /var/www/html
RUN chown -R www-data:www-data /var/www/html

WORKDIR /etc/nginx

CMD ["nginx"]

EXPOSE 80
