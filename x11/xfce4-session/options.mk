# $NetBSD: options.mk,v 1.3 2018/06/04 10:51:56 youri Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-session
PKG_SUPPORTED_OPTIONS=	polkit
PKG_SUGGESTED_OPTIONS=	polkit

.include "../../mk/bsd.options.mk"

PLIST_VARS=	polkit

.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../security/mate-polkit/buildlink3.mk"
PLIST.polkit=	yes
.endif
