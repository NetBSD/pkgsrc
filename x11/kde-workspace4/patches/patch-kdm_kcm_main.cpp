$NetBSD: patch-kdm_kcm_main.cpp,v 1.2 2017/06/25 19:58:04 youri Exp $

Allow $PKG_SYSCONFDIR/kdm/kdmrc to override the one under $PREFIX

--- kdm/kcm/main.cpp.orig	2015-08-12 07:03:15.000000000 +0000
+++ kdm/kcm/main.cpp
@@ -281,8 +281,12 @@ KConfig *KDModule::createTempConfig()
     pTempConfigFile->open();
     QString tempConfigName = pTempConfigFile->fileName();
 
+    QFile confFile (QString::fromLatin1( "/usr/pkg/etc" "/kdm/kdmrc" ));
+    if ( !confFile.exists() )
+	confFile.setFileName (QString::fromLatin1( KDE_CONFDIR "/kdm/kdmrc" ));
+
     KConfig *pSystemKDMConfig = new KConfig(
-        QString::fromLatin1(KDE_CONFDIR "/kdm/kdmrc"), KConfig::SimpleConfig);
+        confFile.fileName(), KConfig::SimpleConfig);
 
     KConfig *pTempConfig = pSystemKDMConfig->copyTo(tempConfigName);
     pTempConfig->sync();
