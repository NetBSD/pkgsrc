$NetBSD: patch-src_plugins_platforminputcontexts_compose_generator_qtablegenerator.cpp,v 1.1 2014/12/30 17:23:46 adam Exp $

PR pkg/48553

--- src/plugins/platforminputcontexts/compose/generator/qtablegenerator.cpp.orig	2014-09-11 10:48:06.000000000 +0000
+++ src/plugins/platforminputcontexts/compose/generator/qtablegenerator.cpp
@@ -76,6 +76,10 @@ void TableGenerator::initPossibleLocatio
     // the QTCOMPOSE environment variable
     if (qEnvironmentVariableIsSet("QTCOMPOSE"))
         m_possibleLocations.append(QString::fromLocal8Bit(qgetenv("QTCOMPOSE")));
+#ifdef X11BASE
+    m_possibleLocations.append(QStringLiteral(X11BASE) + QStringLiteral("/share/X11/locale"));
+    m_possibleLocations.append(QStringLiteral(X11BASE) + QStringLiteral("/lib/X11/locale"));
+#endif
     m_possibleLocations.append(QStringLiteral("/usr/share/X11/locale"));
     m_possibleLocations.append(QStringLiteral("/usr/local/share/X11/locale"));
     m_possibleLocations.append(QStringLiteral("/usr/lib/X11/locale"));
