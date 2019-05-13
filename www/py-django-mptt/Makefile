# $NetBSD: Makefile,v 1.17 2019/05/13 15:58:44 adam Exp $

DISTNAME=	django-mptt-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-mptt/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django-mptt/django-mptt
COMMENT=	Utilities for implementing Modified Preorder Tree Traversal
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-js-asset-[0-9]*:../../www/py-django-js-asset

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
