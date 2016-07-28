#!/bin/sh

exec tail -f \
  /var/log/kern.log \
  /var/log/syslog \
  /var/log/mysql.log \
  /var/log/messages \
  /var/log/postgresql/postgresql-9.4-main.log
