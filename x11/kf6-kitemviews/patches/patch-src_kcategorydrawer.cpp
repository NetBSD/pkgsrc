$NetBSD: patch-src_kcategorydrawer.cpp,v 1.1 2024/05/26 13:36:44 markd Exp $

Avoid ambiguous function call.

--- src/kcategorydrawer.cpp.orig	2024-02-28 10:28:36.635078552 +0000
+++ src/kcategorydrawer.cpp
@@ -78,7 +78,7 @@ void KCategoryDrawer::drawCategory(const
         QRect backgroundRect(option.rect);
         backgroundRect.setLeft(fontMetrics.horizontalAdvance(category) + sidePadding * 2);
         backgroundRect.setRight(backgroundRect.right() - sidePadding);
-        backgroundRect.setTop(backgroundRect.top() + topPadding + ceil(fontMetrics.height() / 2));
+        backgroundRect.setTop(backgroundRect.top() + topPadding + std::ceil(fontMetrics.height() / 2));
         backgroundRect.setHeight(1);
         painter->save();
         painter->setBrush(backgroundColor);
