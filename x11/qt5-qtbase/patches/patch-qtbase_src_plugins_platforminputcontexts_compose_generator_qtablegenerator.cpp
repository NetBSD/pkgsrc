$NetBSD: patch-qtbase_src_plugins_platforminputcontexts_compose_generator_qtablegenerator.cpp,v 1.1 2014/01/28 08:46:14 ryoon Exp $

PR pkg/48553

--- qtbase/src/plugins/platforminputcontexts/compose/generator/qtablegenerator.cpp.orig	2013-12-08 17:09:53.000000000 +0000
+++ qtbase/src/plugins/platforminputcontexts/compose/generator/qtablegenerator.cpp
@@ -81,6 +81,10 @@ void TableGenerator::initPossibleLocatio
     if (qEnvironmentVariableIsSet("QTCOMPOSE")) {
         m_possibleLocations.append(QString(qgetenv("QTCOMPOSE")));
     }
+#ifdef X11BASE
+m_possibleLocations.append(QStringLiteral(X11BASE) + QStringLiteral("/share/X11/locale"));
+m_possibleLocations.append(QStringLiteral(X11BASE) + QStringLiteral("/lib/X11/locale"));
+#endif
     m_possibleLocations.append(QStringLiteral("/usr/share/X11/locale"));
     m_possibleLocations.append(QStringLiteral("/usr/lib/X11/locale"));
 }
