$NetBSD: patch-setup.py,v 1.1 2017/06/24 07:30:18 adam Exp $

Don't rely on UTF-8 being the default system encoding.
https://github.com/aaugustin/websockets/commit/53f61fa9c4c3ba10789a1de86aa7a69b8f623414

--- setup.py.orig	2017-06-24 07:24:21.000000000 +0000
+++ setup.py
@@ -7,10 +7,10 @@ root_dir = os.path.abspath(os.path.dirna
 
 description = "An implementation of the WebSocket Protocol (RFC 6455)"
 
-with open(os.path.join(root_dir, 'README.rst')) as f:
+with open(os.path.join(root_dir, 'README.rst'), encoding='utf-8') as f:
     long_description = f.read()
 
-with open(os.path.join(root_dir, 'websockets', 'version.py')) as f:
+with open(os.path.join(root_dir, 'websockets', 'version.py'), encoding='utf-8') as f:
     exec(f.read())
 
 py_version = sys.version_info[:2]
