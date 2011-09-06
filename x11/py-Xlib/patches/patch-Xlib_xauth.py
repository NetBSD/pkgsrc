$NetBSD: patch-Xlib_xauth.py,v 1.2 2011/09/06 20:45:05 wiz Exp $

Python-3.1 compatibility.
https://sourceforge.net/tracker/?func=detail&aid=3405244&group_id=10350&atid=310350

--- Xlib/xauth.py.orig	2007-06-10 14:11:58.000000000 +0000
+++ Xlib/xauth.py
@@ -42,7 +42,7 @@ class Xauthority:
 
         try:
             raw = open(filename, 'rb').read()
-        except IOError, err:
+        except IOError as err:
             raise error.XauthError('~/.Xauthority: %s' % err)
 
         self.entries = []
@@ -84,12 +84,12 @@ class Xauthority:
                     break
 
                 self.entries.append((family, addr, num, name, data))
-        except struct.error, e:
-            print "Xlib.xauth: warning, failed to parse part of xauthority file (%s), aborting all further parsing" % filename
+        except struct.error as e:
+            print ("Xlib.xauth: warning, failed to parse part of xauthority file (%s), aborting all further parsing" % filename)
             #pass
 
         if len(self.entries) == 0:
-            print "Xlib.xauth: warning, no xauthority details available"
+            print ("Xlib.xauth: warning, no xauthority details available")
             # raise an error?  this should get partially caught by the XNoAuthError in get_best_auth..
 
     def __len__(self):
