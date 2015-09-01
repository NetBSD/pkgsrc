# $NetBSD: options.mk,v 1.1 2015/09/01 00:28:03 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-notes
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
