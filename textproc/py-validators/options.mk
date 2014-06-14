# $NetBSD: options.mk,v 1.1 2014/06/14 14:35:09 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-validators
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=	${PYPKGPREFIX}-test>=2.2.3:../../devel/py-test
.endif
