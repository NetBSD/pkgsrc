$NetBSD: patch-libs_ksysguard_ksgrd_SensorManager.cpp,v 1.1 2012/03/19 19:44:03 markd Exp $

--- libs/ksysguard/ksgrd/SensorManager.cpp.orig	2011-04-01 10:52:43.000000000 +0000
+++ libs/ksysguard/ksgrd/SensorManager.cpp
@@ -81,6 +81,7 @@ void SensorManager::retranslate()
   mDict.insert( QLatin1String( "wired" ), i18n( "Wired Memory" ) );
   mDict.insert( QLatin1String( "execpages" ), i18n( "Exec Pages" ) );
   mDict.insert( QLatin1String( "filepages" ), i18n( "File Pages" ) );
+  mDict.insert( QLatin1String( "anonpages" ), i18n( "Anon Pages" ) );
 
   /* Processes */
   mDict.insert( QLatin1String( "processes" ), i18n( "Processes" ) );
