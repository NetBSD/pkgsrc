$NetBSD: patch-src_ui_OptionDelegate.cpp,v 1.1 2016/01/03 23:37:39 kamil Exp $

Fallback to QItemDelegate::paint() if type is unknown
cherry-pick from https://github.com/OtterBrowser/otter-browser/commit/fd7380a9eec71815115e5a383eea1a7dda33a52a

Patch suggested by upstream

--- src/ui/OptionDelegate.cpp.orig	2016-01-01 20:14:29.000000000 +0000
+++ src/ui/OptionDelegate.cpp
@@ -1,6 +1,6 @@
 /**************************************************************************
 * Otter Browser: Web browser controlled by the user, not vice-versa.
-* Copyright (C) 2013 - 2015 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
+* Copyright (C) 2013 - 2016 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
@@ -34,6 +34,13 @@ void OptionDelegate::paint(QPainter *pai
 {
 	const OptionWidget::OptionType type = getType(index);
 
+	if (type == OptionWidget::UnknownType)
+	{
+		QItemDelegate::paint(painter, option, index);
+
+		return;
+	}
+
 	drawBackground(painter, option, index);
 
 	switch (type)
