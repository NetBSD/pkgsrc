$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 14:53:52 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2015-02-17 07:20:08.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 name ('Data-ICal');
