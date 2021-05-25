$NetBSD: patch-lib_URI_Fetch.pm,v 1.1 2021/05/25 11:20:55 schmonz Exp $

ExtUtils-MakeMaker-7.48 rejects invalid MIN_PERL_VERSION values.
Apply patch from <https://rt.cpan.org/Public/Bug/Display.html?id=133491>.

--- lib/URI/Fetch.pm.orig	2016-07-02 08:35:41.000000000 +0000
+++ lib/URI/Fetch.pm
@@ -1,6 +1,6 @@
 package URI::Fetch;
 $URI::Fetch::VERSION = '0.13';
-use 5.008_001;
+use 5.008001;
 use strict;
 use warnings;
 
