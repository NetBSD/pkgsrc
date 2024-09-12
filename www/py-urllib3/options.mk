# $NetBSD: options.mk,v 1.2 2024/09/12 19:38:21 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-urllib3
PKG_SUPPORTED_OPTIONS=	brotli zstd
PKG_SUGGESTED_OPTIONS=	brotli zstd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbrotli)
DEPENDS+=	${PYPKGPREFIX}-brotli>=1.0.9:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-brotlicffi>=0.8.0:../../archivers/py-brotlicffi
.endif

.if !empty(PKG_OPTIONS:Mzstd)
DEPENDS+=	${PYPKGPREFIX}-zstandard>=0.18.0:../../archivers/py-zstandard
.endif
