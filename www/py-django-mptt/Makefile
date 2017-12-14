# $NetBSD: Makefile,v 1.15 2017/12/14 13:54:17 adam Exp $

DISTNAME=	django-mptt-0.9.0
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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
