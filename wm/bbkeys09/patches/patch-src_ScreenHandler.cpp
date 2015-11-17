$NetBSD: patch-src_ScreenHandler.cpp,v 1.1 2015/11/17 15:59:13 he Exp $

Debug output for missing active window.
Used while debugging what turned out to be an LP64 problem,
but may be useful later, so left here.

--- src/ScreenHandler.cpp.orig	2008-12-22 02:48:59.000000000 +0000
+++ src/ScreenHandler.cpp
@@ -467,6 +467,9 @@ void ScreenHandler::keyPressEvent (const
 				assert(false);  // unhandled action type!
 				break;
 		}
+	} else {
+		if ( _debug )
+			cout <<BBTOOL << ": " << "No active window" <<endl;
 	}
 }
 
@@ -564,18 +567,26 @@ void ScreenHandler::updateActiveWindow()
 {
   assert(_managed);
 
+  if ( _debug )
+    cout <<BBTOOL << ": " << "checking active window" <<endl;
+
   Window a = None;
   _netclient->getValue(_root, _netclient->activeWindow(), XA_WINDOW, a);
 
   if ( None == a ) {
+    if ( _debug )
+      cout <<BBTOOL << ": " << "no active window found" << endl;
     return;
   }
 
   WindowList::iterator it, end = _clients.end();
   for (it = _clients.begin(); it != end; ++it) {
     if ( (*it)->window() == a) {
-      if ( (*it)->getScreenNumber() != _screenNumber )
+      if ( (*it)->getScreenNumber() != _screenNumber ) {
+        if ( _debug )
+          cout <<BBTOOL << ": " << "wrong screen?" << endl;
         return;
+      }
       break;
     }
   }
@@ -597,8 +608,14 @@ void ScreenHandler::updateActiveWindow()
 
       if ( _debug )
         cout <<BBTOOL << ": " << "active window now: [" << bt::toLocale((*_active)->title()) <<"]" <<endl;
+    } else {
+      if ( _debug )
+        cout <<BBTOOL << ": " << "cycling through window list" <<endl;
     }
 
+  } else {
+    if ( _debug )
+      cout <<BBTOOL << ": " << "active window == end, ignored" <<endl;
   }
 
 }
