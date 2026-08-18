# $NetBSD: Makefile,v 1.6 2026/08/18 12:39:52 adam Exp $

DISTNAME=	django_q2-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-q2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-q2.readthedocs.org/
COMMENT=	Multiprocessing distributed task queue for Django
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.10.7:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-django>=5.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-picklefield>=3.1:../../www/py-django-picklefield

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
