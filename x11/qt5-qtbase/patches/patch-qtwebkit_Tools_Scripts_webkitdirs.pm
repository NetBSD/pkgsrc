$NetBSD: patch-qtwebkit_Tools_Scripts_webkitdirs.pm,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support

--- qtwebkit/Tools/Scripts/webkitdirs.pm.orig	2013-11-27 01:01:20.000000000 +0000
+++ qtwebkit/Tools/Scripts/webkitdirs.pm
@@ -355,7 +355,7 @@ sub determineNumberOfCPUs
     } elsif (isWindows() || isCygwin()) {
         # Assumes cygwin
         $numberOfCPUs = `ls /proc/registry/HKEY_LOCAL_MACHINE/HARDWARE/DESCRIPTION/System/CentralProcessor | wc -w`;
-    } elsif (isDarwin() || isFreeBSD()) {
+    } elsif (isDarwin() || isFreeBSD() || isNetBSD()) {
         chomp($numberOfCPUs = `sysctl -n hw.ncpu`);
     }
 }
@@ -1253,6 +1253,11 @@ sub isFreeBSD()
     return ($^O eq "freebsd") || 0;
 }
 
+sub isNetBSD()
+{
+    return ($^O eq "netbsd") || 0;
+}
+
 sub isARM()
 {
     return $Config{archname} =~ /^arm[v\-]/;
