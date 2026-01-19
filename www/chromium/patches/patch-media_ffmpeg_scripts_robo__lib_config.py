$NetBSD: patch-media_ffmpeg_scripts_robo__lib_config.py,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/ffmpeg/scripts/robo_lib/config.py.orig	2026-01-07 00:50:30.000000000 +0000
+++ media/ffmpeg/scripts/robo_lib/config.py
@@ -56,19 +56,13 @@ class RoboConfiguration:
         self._llvm_path = os.path.join(self.chrome_src(), "third_party",
                                        "llvm-build", "Release+Asserts", "bin")
 
-        self.EnsurePathContainsLLVM()
-        self.EnsureNoMakeInfo()
         self.EnsureFFmpegHome()
         self.EnsureGNConfig()
-        self.ComputeBranchName()
 
         if not quiet:
             shell.log(f"Using chrome src: {self.chrome_src()}")
             shell.log(f"Using script dir: {self._script_directory}")
             shell.log(f"Using ffmpeg home: {self.ffmpeg_home()}")
-            shell.log(f"On branch: {self.branch_name()}")
-            if self.sushi_branch_name():
-                shell.log(f"On sushi branch: {self.sushi_branch_name()}")
 
         # Filename that we'll ask generate_gn.py to write git commands to.
         # TODO: Should this use script_directory, or stay with ffmpeg?  As long
@@ -187,9 +181,9 @@ class RoboConfiguration:
 
         if re.match(r"i.86", platform.machine()):
             self._host_architecture = "ia32"
-        elif platform.machine() == "x86_64" or platform.machine() == "AMD64":
+        elif platform.machine() == "x86_64" or platform.machine() == "AMD64" or platform.machine() == "amd64":
             self._host_architecture = "x64"
-        elif platform.machine() == "aarch64":
+        elif platform.machine() == "aarch64" or platform.machine() == "arm64" or platform.machine() == "evbarm":
             self._host_architecture = "arm64"
         elif platform.machine() == "mips32":
             self._host_architecture = "mipsel"
@@ -230,6 +224,12 @@ class RoboConfiguration:
         elif platform.system() == "Windows" or "CYGWIN_NT" in platform.system(
         ):
             self._host_operating_system = "win"
+        elif platform.system() == "OpenBSD":
+            self._host_operating_system = "openbsd"
+        elif platform.system() == "FreeBSD":
+            self._host_operating_system = "freebsd"
+        elif platform.system() == "NetBSD":
+            self._host_operating_system = "netbsd"
         else:
             raise ValueError(f"Unsupported platform: {platform.system()}")
 
@@ -238,8 +238,8 @@ class RoboConfiguration:
         wd = os.getcwd()
         # Walk up the tree until we find src/AUTHORS
         while wd != "/":
-            if os.path.isfile(os.path.join(wd, "src", "AUTHORS")):
-                self._chrome_src = os.path.join(wd, "src")
+            if os.path.isfile(os.path.join(wd, "third_party", "DEPS")):
+                self._chrome_src = wd
                 return
             wd = os.path.dirname(wd)
         raise Exception("could not find src/AUTHORS in any parent of the wd")
