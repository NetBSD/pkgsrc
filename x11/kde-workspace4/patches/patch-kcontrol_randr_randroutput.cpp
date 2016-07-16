$NetBSD: patch-kcontrol_randr_randroutput.cpp,v 1.1 2016/07/16 00:47:00 markd Exp $

fixes for gcc6 from opensuse

--- kcontrol/randr/randroutput.cpp.orig	2015-08-12 07:03:15.000000000 +0000
+++ kcontrol/randr/randroutput.cpp
@@ -202,12 +202,12 @@ void RandROutput::handleEvent(XRROutputC
 		m_connected = (event->connection == RR_Connected);
 		loadSettings(false);
 		if (!m_connected && currentCrtc != None)
-			setCrtc(None);
+			setCrtc(NULL);
 	}
 
 	// check if we are still connected, if not, release the crtc connection
 	if(!m_connected && m_crtc->isValid())
-		setCrtc(None);
+		setCrtc(NULL);
 
 	if(changed)
 		emit outputChanged(m_id, changed);
@@ -267,7 +267,7 @@ ModeList RandROutput::modes() const
 RandRMode RandROutput::mode() const
 {
 	if (!isConnected())
-		return None;
+		return NULL;
 
 	if (!m_crtc)
 		return RandRMode();
