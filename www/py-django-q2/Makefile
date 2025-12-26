# $NetBSD: Makefile,v 1.4 2025/12/26 19:36:12 adam Exp $

DISTNAME=	django_q2-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-q2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-q2.readthedocs.org/
COMMENT=	Multiprocessing distributed task queue for Django
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-picklefield>=3.1:../../www/py-django-picklefield

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
