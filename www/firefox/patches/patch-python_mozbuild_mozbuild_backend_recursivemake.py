$NetBSD: patch-python_mozbuild_mozbuild_backend_recursivemake.py,v 1.1 2024/08/12 14:03:32 ryoon Exp $

* As of 129.0, libxul.so is built with -Wl,-z,defs (no undefined references).
  Supply memalign() from fallback.cpp (Unified_cpp_memory_build0) for NetBSD.
  This approach is completely incorrect, however I do not find the correct
  way to include Unified_cpp_memory_build0.o to objs yet.

--- python/mozbuild/mozbuild/backend/recursivemake.py.orig	2024-08-01 17:32:03.000000000 +0000
+++ python/mozbuild/mozbuild/backend/recursivemake.py
@@ -73,6 +73,8 @@ from ..util import FileAvoidWrite, ensur
 from .common import CommonBackend
 from .make import MakeBackend
 
+import buildconfig
+
 # To protect against accidentally adding logic to Makefiles that belong in moz.build,
 # we check if moz.build-like variables are defined in Makefiles. If they are, we throw
 # an error to encourage the usage of moz.build instead.
@@ -1427,6 +1429,8 @@ class RecursiveMakeBackend(MakeBackend):
             return os.path.normpath(mozpath.relpath(path, obj.objdir))
 
         objs, shared_libs, os_libs, static_libs = self._expand_libs(obj)
+        if buildconfig.substs["OS_ARCH"] == "NetBSD" and obj.name == "libxul.so":
+            objs.append("memory/build/Unified_cpp_memory_build0.o")
 
         obj_target = obj.name
         if isinstance(obj, (Program, SharedLibrary)):
