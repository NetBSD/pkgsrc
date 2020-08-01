# $NetBSD: options.mk,v 1.1 2020/08/01 17:19:46 tnn Exp $

PLIST_VARS+=  gstreamer

PKG_OPTIONS_VAR=	PKG_OPTIONS.wxGTK28
PKG_SUPPORTED_OPTIONS=	gstreamer
PKG_SUGGESTED_OPTIONS=	gstreamer

PLIST.gstreamer=	yes

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.endif
