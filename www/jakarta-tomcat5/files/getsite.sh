#!/bin/sh
TOMCAT_VERSION=${1##*-}
TOMCAT_VERSION=${TOMCAT_VERSION%%.tar.gz}
ftp -o - http://jakarta.apache.org/site/downloads/downloads_tomcat-5.cgi | \
	grep '<option' | \
	tr -d '\n' | \
	sed -e's/[[:space:]]*//g' -e's,[^<]*<optionvalue="\([^"]*\)">[^<]*</option>,\1 ,g' | \
	sed -e"s,\(http:[^ ]*\),\1/jakarta/tomcat-5/v${TOMCAT_VERSION}/bin/,g"
