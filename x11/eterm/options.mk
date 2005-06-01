# $NetBSD: options.mk,v 1.1 2005/06/01 19:44:07 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.eterm

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS=	mmx
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.endif
