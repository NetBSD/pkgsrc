# $NetBSD: Makefile,v 1.17 2025/12/09 09:31:14 adam Exp $

DISTNAME=	webassets-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/webassets/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://webassets.readthedocs.io/
COMMENT=	Asset management for Python web development
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.2:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-zope.dottedname>=6.0:../../textproc/py-zope.dottedname

USE_LANGUAGES=	# empty

REPLACE_PYTHON+=	src/webassets/filter/rjsmin/rjsmin.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
