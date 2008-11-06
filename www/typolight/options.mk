# $NetBSD: options.mk,v 1.1 2008/11/06 11:23:15 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.typolight
PKG_SUPPORTED_OPTIONS=	typolight-liveupdate

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtypolight-liveupdate)
FILES_SUBST+=	TL_UPDATE=YES
.else
FILES_SUBST+=	TL_UPDATE=NO
.endif
