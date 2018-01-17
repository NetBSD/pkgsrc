$NetBSD: patch-src_plugins_platforminputcontexts_compose_generator_qtablegenerator.cpp,v 1.2 2018/01/17 19:30:47 markd Exp $

PR pkg/48553

--- src/plugins/platforminputcontexts/compose/generator/qtablegenerator.cpp.orig	2017-05-26 12:43:31.000000000 +0000
+++ src/plugins/platforminputcontexts/compose/generator/qtablegenerator.cpp
@@ -265,6 +265,10 @@ void TableGenerator::initPossibleLocatio
     m_possibleLocations.reserve(7);
     if (qEnvironmentVariableIsSet("QTCOMPOSE"))
         m_possibleLocations.append(QString::fromLocal8Bit(qgetenv("QTCOMPOSE")));
+#ifdef X11BASE
+    m_possibleLocations.append(QStringLiteral(X11BASE) + QStringLiteral("/share/X11/locale"));
+    m_possibleLocations.append(QStringLiteral(X11BASE) + QStringLiteral("/lib/X11/locale"));
+#endif
     m_possibleLocations.append(QStringLiteral("/usr/share/X11/locale"));
     m_possibleLocations.append(QStringLiteral("/usr/local/share/X11/locale"));
     m_possibleLocations.append(QStringLiteral("/usr/lib/X11/locale"));
