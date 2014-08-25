# $NetBSD: options.mk,v 1.3 2014/08/25 08:30:46 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xdm
PKG_SUPPORTED_OPTIONS+=	inet6 xft2
PKG_SUGGESTED_OPTIONS=	inet6 xft2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mxft2)
.include "../../x11/libXft/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xft
.else
CONFIGURE_ARGS+=	--without-xft
.endif
