# $NetBSD: options.mk,v 1.1 2023/09/06 06:48:36 kleink Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-flask-static-digest
PKG_SUPPORTED_OPTIONS=	brotli
PKG_SUGGESTED_OPTIONS+=	brotli

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbrotli)
DEPENDS+=	${PYPKGPREFIX}-brotli>=1.0.9:../../archivers/py-brotli
.endif
