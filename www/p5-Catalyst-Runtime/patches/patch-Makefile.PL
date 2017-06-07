$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:51:18 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2015-11-16 15:13:57.000000000 +0000
+++ Makefile.PL
@@ -1,5 +1,7 @@
 use strict;
 use warnings;
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install 0.91;
 # Ensure that these get used - yes, M::I loads them for us, but if you're
 # in author mode and don't have them installed, then the error is tres
