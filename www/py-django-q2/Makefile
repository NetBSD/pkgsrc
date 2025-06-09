# $NetBSD: Makefile,v 1.2 2025/06/09 06:42:06 wiz Exp $

DISTNAME=	django_q2-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-q2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-q2.readthedocs.org/
COMMENT=	Multiprocessing distributed task queue for Django
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-django>=4:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-picklefield>=3.0.1:../../www/py-django-picklefield

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
