$NetBSD: patch-nepomuk_core_nepomukmainmodel.cpp,v 1.1 2012/06/16 04:45:40 markd Exp $

ID: 76e0376d7582cfe5b898c56bf3779ca2279dace8
Revert "Disconnect before re-connecting. Soprano does not do that for us."

--- nepomuk/core/nepomukmainmodel.cpp.orig	2012-06-06 20:49:52.000000000 +0000
+++ nepomuk/core/nepomukmainmodel.cpp
@@ -97,7 +97,6 @@ public:
         if ( forced || (!m_socketConnectFailed && !localSocketClient.isConnected()) ) {
             delete localSocketModel;
             localSocketModel = 0;
-            localSocketClient.disconnect();
             QString socketName = KGlobal::dirs()->locateLocal( "socket", "nepomuk-socket" );
             kDebug() << "Connecting to local socket" << socketName;
             if ( localSocketClient.connect( socketName ) ) {
