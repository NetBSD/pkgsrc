$NetBSD: patch-src_FbTk_TextBox.cc,v 1.2 2020/04/17 13:30:49 joerg Exp $

--- src/FbTk/TextBox.cc.orig	2006-03-25 15:42:00.000000000 +0000
+++ src/FbTk/TextBox.cc
@@ -32,6 +32,7 @@
 #else
   #include <ctype.h>
 #endif
+#include <cstdlib>
 #include <X11/keysym.h>
 #include <X11/Xutil.h>
 
@@ -199,7 +200,7 @@ void TextBox::buttonPressEvent(XButtonEv
         int delta = width();
         int tmp = 0;
         for(i = m_start_pos; i <= m_end_pos; i++) {
-            tmp = abs(event.x - font().textWidth(m_text.c_str() + m_start_pos, i - m_start_pos));
+            tmp = abs(event.x - (int)font().textWidth(m_text.c_str() + m_start_pos, i - m_start_pos));
 
             if (tmp < delta) {
                 delta = tmp;
