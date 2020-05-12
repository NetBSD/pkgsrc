# $NetBSD: options.mk,v 1.1 2020/05/12 10:49:35 kleink Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-flask-flatpages
PKG_SUPPORTED_OPTIONS=	pygments
PKG_SUGGESTED_OPTIONS+=	pygments

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpygments)
DEPENDS+=		${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
.endif
