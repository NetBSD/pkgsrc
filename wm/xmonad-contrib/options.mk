# $NetBSD: options.mk,v 1.4 2020/01/11 14:29:29 pho Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xmonad-contrib
PKG_SUPPORTED_OPTIONS=	xft2
PKG_SUGGESTED_OPTIONS=	xft2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxft2)
.include "../../x11/hs-X11-xft/buildlink3.mk"
CONFIGURE_ARGS+=	-fuse_xft
.else
CONFIGURE_ARGS+=	-f-use_xft
.endif
