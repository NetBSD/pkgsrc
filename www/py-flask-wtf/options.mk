# $NetBSD: options.mk,v 1.1 2014/01/10 02:21:53 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-flask-wtf
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=	${PYPKGPREFIX}-flask-babel-[0-9]*:../../www/py-flask-babel
DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
PYSETUPBUILDTARGET=	test
.endif
