$NetBSD: patch-Build.PL,v 1.1 2017/06/08 11:55:34 schmonz Exp $

Fix build with Perl 5.26.0.

--- Build.PL.orig	2016-06-17 09:13:01.000000000 +0000
+++ Build.PL
@@ -1,6 +1,6 @@
 #!/usr/bin/perl
 
-use lib q('.');
+use lib q(.);
 use Po4aBuilder;
 
 my $build = Po4aBuilder->new
