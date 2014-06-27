$NetBSD: patch-lib_Alien_wxWidgets_Utility.pm,v 1.1 2014/06/27 03:29:03 schmonz Exp $

Force intended precedence.

Patch from <https://rt.cpan.org/Public/Bug/Display.html?id=87202>.

--- lib/Alien/wxWidgets/Utility.pm.orig	2014-03-08 14:04:14.000000000 +0000
+++ lib/Alien/wxWidgets/Utility.pm
@@ -74,7 +74,7 @@ sub awx_capture {
 sub awx_cc_is_msvc {
     my( $cc ) = @_;
 
-    return $^O =~ /MSWin32/ and $cc =~ /^cl/i;
+    return ($^O =~ /MSWin32/ and $cc =~ /^cl/i);
 }
 
 sub awx_cc_is_gcc {
