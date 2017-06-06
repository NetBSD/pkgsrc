$NetBSD: patch-Makefile.PL,v 1.1 2017/06/06 14:45:48 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2016-11-11 07:03:29.000000000 +0000
+++ Makefile.PL
@@ -1,4 +1,6 @@
 # Load the Module::Install bundled in ./inc/
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 # Define metadata
