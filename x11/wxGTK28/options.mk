# $NetBSD: options.mk,v 1.2 2020/08/01 17:20:59 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wxGTK28
PKG_SUPPORTED_OPTIONS=	gstreamer
PKG_SUGGESTED_OPTIONS=	gstreamer

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gstreamer
.if !empty(PKG_OPTIONS:Mgstreamer)
PLIST.gstreamer=	yes
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.endif
