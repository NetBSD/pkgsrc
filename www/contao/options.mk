# $NetBSD: options.mk,v 1.1.1.1 2010/07/05 14:39:32 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.contao${CT_VER}
PKG_SUPPORTED_OPTIONS=	contao-liveupdate

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcontao-liveupdate)
FILES_SUBST+=	CT_UPDATE=YES
.else
FILES_SUBST+=	CT_UPDATE=NO
.endif
