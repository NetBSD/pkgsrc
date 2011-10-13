$NetBSD: patch-scripts_build-always.sh,v 1.1 2011/10/13 16:37:03 wiz Exp $

--- scripts/build-always.sh.orig	2011-09-11 11:46:40.000000000 +0000
+++ scripts/build-always.sh
@@ -7,7 +7,7 @@ DAVICAL_VERSION="`head -n1 VERSION`"
 DB_VERSION="`grep 'SELECT new_db_revision' dba/davical.sql | cut -f2 -d'(' | cut -f1-3 -d,`"
 AWL_VERSION="`head -n1 ../awl/VERSION`"
 if [ -z "${AWL_VERSION}" ] ; then
-  AWL_VERSION="'`grep 'want_awl_version' inc/always.php.in | cut -f2 -d= | cut -f1 -d';' | sed 's: ::g'`'"  
+  AWL_VERSION="`grep 'want_awl_version' inc/always.php.in | cut -f2 -d= | cut -f1 -d';' | sed 's: ::g'`"  
 fi
 
 sed -e "/^ *.c->version_string *= *'[^']*' *;/ s/^ *.c->version_string *= *'[^']*' *;/\$c->version_string = '${DAVICAL_VERSION}';/" \
