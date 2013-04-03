$NetBSD: patch-plasma_generic_applets_digital-clock_clock.cpp,v 1.2 2013/04/03 10:51:50 markd Exp $

avoid an infinite loop when starting plasma. (from Sverre Froyen)

--- plasma/generic/applets/digital-clock/clock.cpp.orig	2013-03-01 06:32:24.000000000 +0000
+++ plasma/generic/applets/digital-clock/clock.cpp
@@ -678,32 +678,38 @@ void Clock::generatePixmap()
 
 void Clock::expandFontToMax(QFont &font, const QString &text)
 {
-    bool first = true;
     const QRect rect = contentsRect().toRect();
     int oldWidth = 0;
     int oldHeight = 0;
+    int tryMax = 10;
+    int trys = 0;
+    int pointSize = font.pointSize();
+    int width, height;
 
     // Starting with the given font, increase its size until it'll fill the rect
+    // Try logic protects against an infinite loop
+    // when larger point sizes are missing
     do {
-        if (first) {
-            first = false;
-        } else  {
-            font.setPointSize(font.pointSize() + 1);
-        }
-
+        font.setPointSize(font.pointSize() + 1);
         const QFontMetrics fm(font);
         QRect fr = fm.boundingRect(rect, Qt::TextSingleLine, text);
-        if (oldWidth == fr.width() && oldHeight == fr.height()) {
-            // Largest font size reached.
-            break;
+        if (fr.width() > width || fr.height() > height) {
+            width = fr.width();
+            height = fr.height();
+            if (width > rect.width() || height > rect.height()) {
+                break;
+            }
+            // Real point size has changed and is valid
+            pointSize = font.pointSize();
+            trys = 0;
         }
-        oldWidth = fr.width();
-        oldHeight = fr.height();
-
-        if (fr.width() >= rect.width() || fr.height() >= rect.height()) {
-            break;
+        else {
+            // Real point size did not change
+            trys++;
         }
-    } while (true);
+    } while (trys < tryMax);
+
+    font.setPointSize(pointSize);
 }
 
 void Clock::prepareFont(QFont &font, QRect &rect, const QString &text, bool singleline)
