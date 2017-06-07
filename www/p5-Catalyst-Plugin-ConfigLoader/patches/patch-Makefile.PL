$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:51:18 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2014-04-16 13:36:16.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install 0.95;
 
 if ( -e 'MANIFEST.SKIP' ) {
