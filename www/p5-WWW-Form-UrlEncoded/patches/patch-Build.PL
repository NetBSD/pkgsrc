$NetBSD: patch-Build.PL,v 1.1 2017/06/06 14:58:09 ryoon Exp $

* Fix build with Perl 5.26.0

--- Build.PL.orig	2015-11-19 00:33:39.000000000 +0000
+++ Build.PL
@@ -9,6 +9,8 @@ use strict;
 use warnings;
 use utf8;
 
+use FindBin;
+use lib $FindBin::Bin;
 use builder::MyBuilder;
 use File::Basename;
 use File::Spec;
