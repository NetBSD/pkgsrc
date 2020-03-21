$NetBSD: patch-setup.py,v 1.1 2020/03/21 17:02:14 gutteridge Exp $

Add NetBSD support.

--- setup.py.orig	2020-03-19 20:58:31.000000000 +0000
+++ setup.py
@@ -85,6 +85,7 @@ CONFIGURE_WITH_ICU_CONFIG = {
     'win32': False,   # no icu-config
     'sunos5': False,  # not tested
     'cygwin': False,  # not tested
+    'netbsd': False,
 }
 
 CONFIGURE_WITH_PKG_CONFIG = {
@@ -94,6 +95,7 @@ CONFIGURE_WITH_PKG_CONFIG = {
     'win32': False,   # no pkg-config ?
     'sunos5': False,  # not tested
     'cygwin': False,  # not tested
+    'netbsd': True,
 }
 
 INCLUDES = {
@@ -103,6 +105,7 @@ INCLUDES = {
     'win32': ['c:/icu/include'],
     'sunos5': [],
     'cygwin': [],
+    'netbsd': [],
 }
 
 VER_FLAGS = {
@@ -112,6 +115,7 @@ VER_FLAGS = {
     'win32': ['/DPYICU_VER=\\"%s\\"' %(VERSION)],
     'sunos5': ['-DPYICU_VER="%s"' %(VERSION)],
     'cygwin': ['-DPYICU_VER="%s"' %(VERSION)],
+    'netbsd': ['-DPYICU_VER="%s"' %(VERSION)],
 }
 
 CFLAGS = {
@@ -121,6 +125,7 @@ CFLAGS = {
     'win32': ['/Zc:wchar_t', '/EHsc'],
     'sunos5': ['-std=c++11'],
     'cygwin': ['-D_GNU_SOURCE=1', '-std=c++11'],
+    'netbsd': [],
 }
 
 # added to CFLAGS when setup is invoked with --debug
@@ -131,6 +136,7 @@ DEBUG_CFLAGS = {
     'win32': ['/Od', '/DDEBUG'],
     'sunos5': ['-DDEBUG'],
     'cygwin': ['-Og', '-g', '-DDEBUG'],
+    'netbsd': ['-O0', '-g', '-DDEBUG'],
 }
 
 LFLAGS = {
@@ -140,6 +146,7 @@ LFLAGS = {
     'win32': ['/LIBPATH:c:/icu/lib'],
     'sunos5': [],
     'cygwin': [],
+    'netbsd': [],
 }
 
 LIBRARIES = {
@@ -149,6 +156,7 @@ LIBRARIES = {
     'win32': ['icuin', 'icuuc', 'icudt'],
     'sunos5': ['icui18n', 'icuuc', 'icudata'],
     'cygwin': ['icui18n', 'icuuc', 'icudata'],
+    'netbsd': [],
 }
 
 platform = sys.platform
@@ -156,6 +164,8 @@ if platform.startswith(('linux', 'gnu'))
     platform = 'linux'
 elif platform.startswith('freebsd'):
     platform = 'freebsd'
+elif platform.startswith('netbsd'):
+    platform = 'netbsd'
 
 if 'PYICU_INCLUDES' in os.environ:
     _includes = os.environ['PYICU_INCLUDES'].split(os.pathsep)
