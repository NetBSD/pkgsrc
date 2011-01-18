$NetBSD: patch-ah,v 1.1 2011/01/18 10:59:13 markd Exp $

Handle location of xkb/rules in NetBSD's intree X11R7
(/usr/X11R7/lib/X11/xkb/rules)

--- kcontrol/keyboard/xkb_rules.cpp.orig	2010-08-27 10:10:21.000000000 +0200
+++ kcontrol/keyboard/xkb_rules.cpp	2011-01-11 21:47:03.000000000 +0100
@@ -138,12 +138,18 @@
 {
 	QString rulesFile;
 	QString rulesName = Rules::getRulesName();
+	QString xkbRulesSubDir = "xkb/rules";
 
 	if ( ! rulesName.isNull() ) {
 		QString xkbParentDir;
 
 		QString base(XLIBDIR);
 		if( base.count('/') >= 3 ) {
+			// /usr/X11R7/lib/X11 with xkb/rules subdirectory below it
+			QDir xkbRulesDir(base + "/" + xkbRulesSubDir);
+			if( xkbRulesDir.exists() ) {
+				xkbParentDir = base;
+			} else {
 			// .../usr/lib/X11 -> /usr/share/X11/xkb vs .../usr/X11/lib -> /usr/X11/share/X11/xkb
 			QString delta = base.endsWith("X11") ? "/../../share/X11" : "/../share/X11";
 			QDir baseDir(base + delta);
@@ -157,12 +163,13 @@
 				}
 			}
 		}
+		}
 
 		if( xkbParentDir.isEmpty() ) {
 			xkbParentDir = "/usr/share/X11";
 		}
 
-		rulesFile = QString("%1/xkb/rules/%2.xml").arg(xkbParentDir, rulesName);
+		rulesFile = QString("%1/%2/%3.xml").arg(xkbParentDir, xkbRulesSubDir, rulesName);
 	}
 
 	return rulesFile;
