$NetBSD: patch-setup.py,v 1.1 2014/12/01 11:54:48 joerg Exp $

--- setup.py.orig	2014-11-28 20:58:54.000000000 +0000
+++ setup.py
@@ -248,12 +248,13 @@ class build_ext(_build_ext):
         prog = 'check_%s' % ext.feature_name
         log.info("checking if %s is linkable" % ext.feature_name)
         try:
+            linker_flags = ["%s%s/lib" % (os.environ['COMPILER_RPATH_FLAG'], os.environ['PREFIX']), "-L%s/lib" % os.environ['PREFIX']]
             self.compiler.link_executable([obj], prog,
                     output_dir=self.build_temp,
                     libraries=ext.libraries,
                     library_dirs=ext.library_dirs,
                     runtime_library_dirs=ext.runtime_library_dirs,
-                    extra_postargs=(ext.extra_link_args or []))
+                    extra_postargs=(ext.extra_link_args or [])+linker_flags)
         except LinkError:
             log.warn("")
             log.warn("%s is not found or a linker error: forcing --%s"
