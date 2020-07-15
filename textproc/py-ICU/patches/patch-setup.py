$NetBSD: patch-setup.py,v 1.2 2020/07/15 15:04:18 adam Exp $

Add NetBSD support.

--- setup.py.orig	2020-05-26 22:08:37.000000000 +0000
+++ setup.py
@@ -86,6 +86,7 @@ CONFIGURE_WITH_ICU_CONFIG = {
     'win32': False,   # no icu-config
     'sunos5': False,  # not tested
     'cygwin': False,  # not tested
+    'netbsd': False,
 }
 
 CONFIGURE_WITH_PKG_CONFIG = {
@@ -95,6 +96,7 @@ CONFIGURE_WITH_PKG_CONFIG = {
     'win32': False,   # no pkg-config ?
     'sunos5': False,  # not tested
     'cygwin': False,  # not tested
+    'netbsd': True,
 }
 
 INCLUDES = {
@@ -104,6 +106,7 @@ INCLUDES = {
     'win32': ['c:/icu/include'],
     'sunos5': [],
     'cygwin': [],
+    'netbsd': [],
 }
 
 VER_FLAGS = {
@@ -119,6 +122,8 @@ VER_FLAGS = {
                '-DPYICU_ICU_MAX_VER="%s"' %(ICU_MAX_MAJOR_VERSION)],
     'cygwin': ['-DPYICU_VER="%s"' %(VERSION),
                '-DPYICU_ICU_MAX_VER="%s"' %(ICU_MAX_MAJOR_VERSION)],
+    'netbsd': ['-DPYICU_VER="%s"' %(VERSION),
+               '-DPYICU_ICU_MAX_VER="%s"' %(ICU_MAX_MAJOR_VERSION)],
 }
 
 PEDANTIC_FLAGS = {
@@ -137,6 +142,7 @@ CFLAGS = {
     'win32': ['/Zc:wchar_t', '/EHsc'],
     'sunos5': ['-std=c++11'],
     'cygwin': ['-D_GNU_SOURCE=1', '-std=c++11'],
+    'netbsd': [],
 }
 
 # added to CFLAGS when setup is invoked with --debug
@@ -147,6 +153,7 @@ DEBUG_CFLAGS = {
     'win32': ['/Od', '/DDEBUG'],
     'sunos5': ['-DDEBUG'],
     'cygwin': ['-Og', '-g', '-DDEBUG'],
+    'netbsd': ['-O0', '-g', '-DDEBUG'],
 }
 
 LFLAGS = {
@@ -156,6 +163,7 @@ LFLAGS = {
     'win32': ['/LIBPATH:c:/icu/lib'],
     'sunos5': [],
     'cygwin': [],
+    'netbsd': [],
 }
 
 LIBRARIES = {
@@ -165,6 +173,7 @@ LIBRARIES = {
     'win32': ['icuin', 'icuuc', 'icudt'],
     'sunos5': ['icui18n', 'icuuc', 'icudata'],
     'cygwin': ['icui18n', 'icuuc', 'icudata'],
+    'netbsd': [],
 }
 
 platform = sys.platform
@@ -172,6 +181,8 @@ if platform.startswith(('linux', 'gnu'))
     platform = 'linux'
 elif platform.startswith('freebsd'):
     platform = 'freebsd'
+elif platform.startswith('netbsd'):
+    platform = 'netbsd'
 
 if 'PYICU_INCLUDES' in os.environ:
     _includes = os.environ['PYICU_INCLUDES'].split(os.pathsep)
