# $NetBSD: options.mk,v 1.1 2024/03/19 10:58:01 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.py-urllib3
PKG_SUPPORTED_OPTIONS=		brotli zstd
PKG_SUGGESTED_OPTIONS=		brotli zstd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbrotli)
DEPENDS+=	${PYPKGPREFIX}-brotli>=1.0.9:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-brotlicffi>=0.8.0:../../archivers/py-brotlicffi
.endif

.if !empty(PKG_OPTIONS:Mzstd)
DEPENDS+=	${PYPKGPREFIX}-zstandard>=0.18.0:../../archivers/py-zstandard
.endif
