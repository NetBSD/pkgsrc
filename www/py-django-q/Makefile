# $NetBSD: Makefile,v 1.4 2025/04/22 15:18:02 adam Exp $

DISTNAME=	django-q-1.3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-q/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-q.readthedocs.org/
COMMENT=	Multiprocessing distributed task queue for Django
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-arrow>=1.1.0:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-blessed>=1.17.6:../../devel/py-blessed
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-picklefield>=3.0.1:../../www/py-django-picklefield

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
