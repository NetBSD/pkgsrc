# $NetBSD: options.mk,v 1.3 2022/05/01 09:45:42 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-flask-flatpages
PKG_SUPPORTED_OPTIONS=	pygments
PKG_SUGGESTED_OPTIONS+=	pygments

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpygments)
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
.endif
