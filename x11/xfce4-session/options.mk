# $NetBSD: options.mk,v 1.4 2020/05/03 20:48:57 gutteridge Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-session
PKG_SUPPORTED_OPTIONS=	polkit
PKG_SUGGESTED_OPTIONS=	polkit

.include "../../mk/bsd.options.mk"

PLIST_VARS=	polkit

.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../security/mate-polkit/buildlink3.mk"
PLIST.polkit=	yes
.else
# For the edge case when Polkit is installed on the system, but isn't
# intended to be enabled, we must explicitly disable it.
CONFIGURE_ARGS+=	--disable-polkit
.endif
