$NetBSD: patch-setup.py,v 1.2 2019/02/04 01:11:15 gutteridge Exp $

Use PKGMANDIR and sort out (C|CPP|LD)FLAGS.

--- setup.py.orig	2019-01-19 08:36:53.000000000 +0000
+++ setup.py
@@ -180,41 +180,14 @@ def init_env(
         df += ' -Og'
     optimize = df if debug or sanitize else '-O3'
     sanitize_args = get_sanitize_args(cc, ccver) if sanitize else set()
-    cppflags = os.environ.get(
-        'OVERRIDE_CPPFLAGS', (
-            '-D{}DEBUG'
-        ).format(
-            ('' if debug else 'N'),
-        )
-    )
-    cppflags = shlex.split(cppflags)
-    cflags = os.environ.get(
-        'OVERRIDE_CFLAGS', (
-            '-Wextra -Wno-missing-field-initializers -Wall -std=c11'
-            ' -pedantic-errors -Werror {} {} -fwrapv {} {} -pipe {} -fvisibility=hidden'
-        ).format(
-            optimize,
-            ' '.join(sanitize_args),
-            stack_protector,
-            missing_braces,
-            '-march=native' if native_optimizations else '',
-        )
-    )
-    cflags = shlex.split(cflags) + shlex.split(
-        sysconfig.get_config_var('CCSHARED')
-    )
-    ldflags = os.environ.get(
-        'OVERRIDE_LDFLAGS',
-        '-Wall ' + ' '.join(sanitize_args) + ('' if debug else ' -O3')
-    )
-    ldflags = shlex.split(ldflags)
+    cppflags = shlex.split(os.environ.get('CPPFLAGS', ''))
+    cflags = shlex.split(os.environ.get('CFLAGS', ''))
+    cflags.append('-std=c99')
+    cflags.append('-fwrapv')
+    cflags.append('-fvisibility=hidden')
+    cflags.append('-fPIC')
+    ldflags = shlex.split(os.environ.get('LDFLAGS', ''))
     ldflags.append('-shared')
-    cppflags += shlex.split(os.environ.get('CPPFLAGS', ''))
-    cflags += shlex.split(os.environ.get('CFLAGS', ''))
-    ldflags += shlex.split(os.environ.get('LDFLAGS', ''))
-    if not debug and not sanitize:
-        # See https://github.com/google/sanitizers/issues/647
-        cflags.append('-flto'), ldflags.append('-flto')
 
     if profile:
         cppflags.append('-DWITH_PROFILER')
@@ -518,14 +491,12 @@ def build_asan_launcher(args):
 
 
 def build_linux_launcher(args, launcher_dir='.', for_bundle=False, sh_launcher=False, for_freeze=False):
-    cflags = '-Wall -Werror -fpie'.split()
-    cppflags = []
-    libs = []
+    cflags = shlex.split(os.environ.get('CFLAGS', ''))
+    cppflags = shlex.split(os.environ.get('CPPFLAGS', ''))
+    libs = shlex.split(os.environ.get('LIBS', ''))
     if args.profile:
         cppflags.append('-DWITH_PROFILER'), cflags.append('-g')
         libs.append('-lprofiler')
-    else:
-        cflags.append('-O3')
     if for_bundle or for_freeze:
         cppflags.append('-DFOR_BUNDLE')
         cppflags.append('-DPYVER="{}"'.format(sysconfig.get_python_version()))
@@ -534,8 +505,6 @@ def build_linux_launcher(args, launcher_
     cppflags.append('-DLIB_DIR_NAME="{}"'.format(args.libdir_name.strip('/')))
     pylib = get_python_flags(cflags)
     exe = 'kitty-profile' if args.profile else 'kitty'
-    cppflags += shlex.split(os.environ.get('CPPFLAGS', ''))
-    cflags += shlex.split(os.environ.get('CFLAGS', ''))
     ldflags = shlex.split(os.environ.get('LDFLAGS', ''))
     if for_freeze:
         ldflags += ['-Wl,-rpath,$ORIGIN/../lib']
@@ -550,7 +519,7 @@ def build_linux_launcher(args, launcher_
 
 
 def copy_man_pages(ddir):
-    mandir = os.path.join(ddir, 'share', 'man')
+    mandir = os.environ['PKGMANDIR']
     safe_makedirs(mandir)
     try:
         shutil.rmtree(os.path.join(mandir, 'man1'))
