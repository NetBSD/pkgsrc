$NetBSD: patch-src_ui_Dialog.cpp,v 1.1 2016/01/03 23:37:39 kamil Exp $

Always mark dialogs as restored
cherry-pick from https://github.com/OtterBrowser/otter-browser/commit/67c2ae72cc57c80412bc5701e5fb7f89cb0ba9da

Suggested by upstream

--- src/ui/Dialog.cpp.orig	2016-01-01 20:14:29.000000000 +0000
+++ src/ui/Dialog.cpp
@@ -45,12 +45,11 @@ void Dialog::showEvent(QShowEvent *event
 		}
 		else
 		{
+			const QString name = normalizeDialogName(objectName());
 			const QJsonObject object = QJsonDocument::fromJson(file.readAll()).object();
 
 			file.close();
 
-			const QString name = normalizeDialogName(objectName());
-
 			if (object.contains(name))
 			{
 				QJsonObject size = object.value(name).toObject().value(QLatin1String("size")).toObject();
@@ -60,9 +59,9 @@ void Dialog::showEvent(QShowEvent *event
 					resize(size.value(QLatin1String("width")).toInt(), size.value(QLatin1String("height")).toInt());
 				}
 			}
-
-			m_wasRestored = true;
 		}
+
+		m_wasRestored = true;
 	}
 
 	QDialog::showEvent(event);
