$NetBSD: patch-build_Wx_build_MakeMaker.pm,v 1.1 2013/01/19 17:14:49 schmonz Exp $

Don't let extra Mac stuff not in the PLIST get built on Darwin.

--- build/Wx/build/MakeMaker.pm.orig	2012-04-26 02:28:24.000000000 +0000
+++ build/Wx/build/MakeMaker.pm
@@ -139,6 +139,11 @@ BEGIN {
  SWITCH: {
     local $_ = $Config{osname};
 
+    # pkgsrc
+    m/.*/ and do {
+      goto DEFAULT;
+    };
+
     # Win32
     m/MSWin32/ and do {
       local $_ = File::Basename::basename( $Config{cc} );
@@ -156,6 +161,7 @@ BEGIN {
       last SWITCH;
     };
 
+    DEFAULT:
     # default
     $package_to_use = 'Any_wx_config';
     last SWITCH;
