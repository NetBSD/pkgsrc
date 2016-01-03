$NetBSD: patch-src_ui_Window.cpp,v 1.1 2016/01/03 23:37:39 kamil Exp $

Try to return first address field from the list if none was matched
cherry-pick from https://github.com/OtterBrowser/otter-browser/commit/d1a1b0bbc8d80d0d7ed7a1fbbf83975a5ddea69e

Patch suggested by upstream

--- src/ui/Window.cpp.orig	2016-01-01 20:14:29.000000000 +0000
+++ src/ui/Window.cpp
@@ -596,7 +596,7 @@ AddressWidget* Window::findAddressWidget
 		}
 	}
 
-	return NULL;
+	return m_addressWidgets.value(0, NULL);
 }
 
 Window* Window::clone(bool cloneHistory, QWidget *parent)
