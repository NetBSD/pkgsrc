# $NetBSD: options.mk,v 1.1 2014/05/03 02:13:35 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-flask-testing
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=		${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
.include "../../lang/python/pyversion.mk"
.if ${PYPACKAGE:C/([0-9])[0-9]/\1/1} == "python2"
DEPENDS+=		${PYPKGPREFIX}-twill-[0-9]*:../../www/py-twill
.endif
.endif
