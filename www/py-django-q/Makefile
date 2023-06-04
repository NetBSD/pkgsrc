# $NetBSD: Makefile,v 1.1 2023/06/04 02:57:12 markd Exp $

DISTNAME=	django-q-1.3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-q/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-q.readthedocs.org/
COMMENT=	Multiprocessing distributed task queue for Django
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-arrow>=1.1.0:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-blessed>=1.1.0:../../devel/py-blessed
DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django2
DEPENDS+=	${PYPKGPREFIX}-django-picklefield>=3.0.1:../../www/py-django-picklefield

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
