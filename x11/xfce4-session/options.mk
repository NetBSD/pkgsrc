# $NetBSD: options.mk,v 1.1 2016/12/04 13:50:08 martin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-session
PKG_SUPPORTED_OPTIONS=	polkit
PKG_SUGGESTED_OPTIONS=	polkit

.include "../../mk/bsd.options.mk"

PLIST_VARS	= polkit

.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../security/polkit/buildlink3.mk"
PLIST.polkit	= yes
.endif


