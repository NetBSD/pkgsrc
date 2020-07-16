--- configs/keygen.sh.orig	2018-07-09 18:17:23.000000000 -0700
+++ configs/keygen.sh	2020-07-07 12:39:12.562183624 -0700
@@ -1,5 +1,8 @@
 #! /bin/sh
 
+# Dump the generated keys in @SHIB_CONFDIR@ by default
+cd @SHIB_CONFDIR@
+
 while getopts n:h:u:g:o:e:y:bf c
      do
          case $c in
