$NetBSD: patch-Build.PL,v 1.1 2017/06/09 17:08:58 ryoon Exp $

* Fix build with Perl 5.26.0

--- Build.PL.orig	2013-01-11 06:01:51.000000000 +0000
+++ Build.PL
@@ -1,5 +1,7 @@
 use strict;
 use warnings;
+use FindBin;
+use lib $FindBin::Bin;
 use GvaScript_Builder;
 
 my $builder = GvaScript_Builder->new(
