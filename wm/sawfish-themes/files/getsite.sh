#!/bin/sh
# $NetBSD: getsite.sh,v 1.1.1.1 2002/10/07 17:00:44 jschauma Exp $
# generate MASTER_SITE URL for themes from themes.freshmeat.net

THEME=${1%%-[0-9]*.*}
BASEURL="http://download.freshmeat.net/themes"
echo "${BASEURL}/${THEME}/"
