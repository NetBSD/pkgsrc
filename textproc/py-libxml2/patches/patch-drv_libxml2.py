$NetBSD: patch-drv_libxml2.py,v 1.1 2013/10/03 07:52:32 prlw1 Exp $

Python 3 fix
commit 6c9c611b

--- drv_libxml2.py.orig	2009-07-30 15:24:34.000000000 +0000
+++ drv_libxml2.py
@@ -34,12 +34,20 @@ TODO
 
 """
 
-__author__  = u"Stéphane Bidoul <sbi@skynet.be>"
+__author__  = "Stéphane Bidoul <sbi@skynet.be>"
 __version__ = "0.3"
 
+import sys
 import codecs
-from types import StringType, UnicodeType
-StringTypes = (StringType,UnicodeType)
+
+if sys.version < "3":
+    __author__  = codecs.unicode_escape_decode(__author__)[0]
+
+    from types import StringType, UnicodeType
+    StringTypes = (StringType,UnicodeType)
+
+else:
+    StringTypes = (str)
 
 from xml.sax._exceptions import *
 from xml.sax import xmlreader, saxutils
@@ -65,7 +73,7 @@ def _d(s):
 
 try:
     import libxml2
-except ImportError, e:
+except ImportError as e:
     raise SAXReaderNotAvailable("libxml2 not available: " \
                                 "import error was: %s" % e)
 
