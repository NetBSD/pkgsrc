$NetBSD: patch-lib_Locale_Po4a_Sgml.pm,v 1.1 2023/07/03 21:16:53 wiz Exp $

Fix build with gettext 0.22
https://github.com/jpalus/po4a/commit/9f102bba1b279294de637ad5ec93c64cf7da70e7

--- lib/Locale/Po4a/Sgml.pm.orig	2023-07-03 21:10:46.730796044 +0000
+++ lib/Locale/Po4a/Sgml.pm
@@ -773,7 +773,7 @@ sub parse_file {
             while ( $origfile =~ /^(.*?)&$key(;.*$|[^-_:.A-Za-z0-9].*$|$)/s ) {
 
                 # Since we will include a new file, we
-                # must do a new round of substitutions.
+                # must do a new round of substitutions.
                 $dosubstitution = 1;
                 my ( $begin, $end ) = ( $1, $2 );
                 $end = "" unless ( defined $end );
