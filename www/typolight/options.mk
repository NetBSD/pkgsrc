# $NetBSD: options.mk,v 1.2 2009/04/26 03:34:13 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.typolight${TL_VER}
PKG_SUPPORTED_OPTIONS=	typolight-liveupdate

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtypolight-liveupdate)
FILES_SUBST+=	TL_UPDATE=YES
.else
FILES_SUBST+=	TL_UPDATE=NO
.endif
