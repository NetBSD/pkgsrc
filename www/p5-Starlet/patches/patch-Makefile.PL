$NetBSD: patch-Makefile.PL,v 1.1 2017/06/07 00:01:33 ryoon Exp $

* Fix build with Perl 5.26.0

--- Makefile.PL.orig	2016-05-17 07:09:41.000000000 +0000
+++ Makefile.PL
@@ -1,3 +1,5 @@
+use FindBin;
+use lib $FindBin::Bin;
 use inc::Module::Install;
 
 all_from 'lib/Starlet.pm';
