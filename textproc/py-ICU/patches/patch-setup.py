$NetBSD: patch-setup.py,v 1.5 2024/05/29 17:51:10 adam Exp $

Add NetBSD support.

--- setup.py.orig	2024-04-29 20:14:33.000000000 +0000
+++ setup.py
@@ -64,6 +64,8 @@ if platform.startswith(('linux', 'gnu'))
     platform = 'linux'
 elif platform.startswith('freebsd'):
     platform = 'freebsd'
+elif platform.startswith('netbsd'):
+    platform = 'netbsd'
 
 
 CONFIGURE_WITH_ICU_CONFIG = {
@@ -73,6 +75,7 @@ CONFIGURE_WITH_ICU_CONFIG = {
     'win32': False,   # no icu-config
     'sunos5': False,  # not tested
     'cygwin': False,  # not tested
+    'netbsd': False,
 }
 
 CONFIGURE_WITH_PKG_CONFIG = {
@@ -82,6 +85,7 @@ CONFIGURE_WITH_PKG_CONFIG = {
     'win32': False,   # no pkg-config ?
     'sunos5': False,  # not tested
     'cygwin': False,  # not tested
+    'netbsd': True,
 }
 
 
@@ -114,6 +118,7 @@ INCLUDES = {
     'win32': ['c:/icu/include'],
     'sunos5': [],
     'cygwin': [],
+    'netbsd': [],
 }
 
 if sys.platform == 'win32' and sys.version_info < (3,9):
@@ -132,6 +137,7 @@ PEDANTIC_FLAGS = {
     'win32': [],
     'sunos5': [],
     'cygwin': ['-pedantic'],
+    'netbsd': [],
 }
 
 CFLAGS = {
@@ -141,6 +147,7 @@ CFLAGS = {
     'win32': ['/Zc:wchar_t', '/EHsc'],
     'sunos5': ['-std=c++17'],
     'cygwin': ['-D_GNU_SOURCE=1', '-std=c++17'],
+    'netbsd': [],
 }
 
 # added to CFLAGS when setup is invoked with --debug
@@ -151,6 +158,7 @@ DEBUG_CFLAGS = {
     'win32': ['/Od', '/DDEBUG'],
     'sunos5': ['-DDEBUG'],
     'cygwin': ['-Og', '-g', '-DDEBUG'],
+    'netbsd': ['-O0', '-g', '-DDEBUG'],
 }
 
 LFLAGS = {
@@ -160,6 +168,7 @@ LFLAGS = {
     'win32': ['/LIBPATH:c:/icu/lib'],
     'sunos5': [],
     'cygwin': [],
+    'netbsd': [],
 }
 
 LIBRARIES = {
@@ -169,6 +178,7 @@ LIBRARIES = {
     'win32': ['icuin', 'icuuc', 'icudt'],
     'sunos5': ['icui18n', 'icuuc', 'icudata'],
     'cygwin': ['icui18n', 'icuuc', 'icudata'],
+    'netbsd': [],
 }
 
 if 'PYICU_INCLUDES' in os.environ:
