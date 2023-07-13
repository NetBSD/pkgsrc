# $NetBSD: Makefile,v 1.2 2023/07/13 10:03:29 wiz Exp $

DISTNAME=	django-q-1.3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-q/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-q.readthedocs.org/
COMMENT=	Multiprocessing distributed task queue for Django
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-arrow>=1.1.0:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-blessed>=1.1.0:../../devel/py-blessed
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-django-picklefield>=3.0.1:../../www/py-django-picklefield

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
