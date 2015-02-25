$NetBSD: patch-Makefile.PL,v 1.3 2015/02/25 11:43:54 adam Exp $

Use CONFDIR (not ETCDIR) to install default configuration files.

--- Makefile.PL.orig	2015-02-25 11:27:53.000000000 +0000
+++ Makefile.PL
@@ -39,8 +39,8 @@ unless(open(INST, ">install_all.sh")) {
 }
 print INST qq{#!/bin/sh
 test ! -d "$DESTDIR$BINDIR" && mkdir -p $DESTDIR$BINDIR
-test ! -d "$DESTDIR$ETCDIR" && mkdir -p $DESTDIR$ETCDIR
-test ! -d "$DESTDIR$ETCDIR/lang" && mkdir -p $DESTDIR$ETCDIR/lang
+test ! -d "$DESTDIR$CONFDIR" && mkdir -p $DESTDIR$CONFDIR
+test ! -d "$DESTDIR$CONFDIR/lang" && mkdir -p $DESTDIR$CONFDIR/lang
 test ! -d "$DESTDIR$HTMLDIR" && mkdir -p $DESTDIR$HTMLDIR
 test ! -d "$DESTDIR$HTMLDIR/images" && mkdir -p $DESTDIR$HTMLDIR/images
 };
@@ -56,10 +56,10 @@ test ! -d "$DESTDIR$MANDIR" && mkdir -p 
 
 # Copy files that must not be overriden 
 for file in squidanalyzer.conf network-aliases user-aliases excluded included; do
-if [ -r $DESTDIR$ETCDIR/\$file ]; then
-	install -m 644 etc/\$file $DESTDIR$ETCDIR/\$file.sample
+if [ -r $DESTDIR$CONFDIR/\$file ]; then
+	install -m 644 etc/\$file $DESTDIR$CONFDIR/\$file.sample
 else
-	install -m 644 etc/\$file $DESTDIR$ETCDIR/\$file
+	install -m 644 etc/\$file $DESTDIR$CONFDIR/\$file
 fi
 done
 install -m 755 squid-analyzer $DESTDIR$BINDIR/
@@ -73,7 +73,7 @@ install -m 644 resources/images/back-arr
 install -m 644 resources/images/info.png $DESTDIR$HTMLDIR/images/
 install -m 644 resources/images/network.png $DESTDIR$HTMLDIR/images/
 install -m 644 resources/images/user.png $DESTDIR$HTMLDIR/images/
-install -m 644 lang/* $DESTDIR$ETCDIR/lang/
+install -m 644 lang/* $DESTDIR$CONFDIR/lang/
 pod2text doc/SquidAnalyzer.pod README
 pod2man doc/SquidAnalyzer.pod squid-analyzer.3
 };
