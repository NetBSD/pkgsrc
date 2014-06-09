# $NetBSD: options.mk,v 1.2 2014/06/09 10:52:47 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-django-tastypie
PKG_SUPPORTED_OPTIONS=	digest
PKG_SUGGESTED_OPTIONS+=	digest

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdigest)
.include "../../lang/python/pyversion.mk"
.  if ${PYVERSSUFFIX} > 2.7
DEPENDS+=	${PYPKGPREFIX}-python-digest-[0-9]*:../../www/py-python3-digest
.  else
DEPENDS+=	${PYPKGPREFIX}-python-digest-[0-9]*:../../www/py-python-digest
.  endif
.endif
