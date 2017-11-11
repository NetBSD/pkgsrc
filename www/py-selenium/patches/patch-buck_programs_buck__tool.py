$NetBSD: patch-buck_programs_buck__tool.py,v 1.1 2017/11/11 21:30:21 tnn Exp $

openjdk8 on NetBSD gets very confused if argv[0] isn't java.

--- ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/programs/buck_tool.py.orig	2017-09-21 14:10:58.000000000 +0000
+++ ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/programs/buck_tool.py
@@ -272,6 +272,7 @@ class BuckTool(object):
         java = which('java')
         if java is None:
             raise BuckToolException('Could not find java on $PATH')
+        command[0] = java
         with Tracing('buck', args={'command': command}):
             return subprocess.call(command,
                                    cwd=self._buck_project.root,
@@ -442,6 +443,7 @@ class BuckTool(object):
                     os.close(dev_null_fd)
 
                 creationflags = 0
+            command[0] = which("java")
             process = subprocess.Popen(
                 command,
                 executable=which("java"),
