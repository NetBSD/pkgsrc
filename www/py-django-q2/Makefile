# $NetBSD: Makefile,v 1.1 2025/06/04 11:02:22 markd Exp $

DISTNAME=	django_q2-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-q2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-q2.readthedocs.org/
COMMENT=	Multiprocessing distributed task queue for Django
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=4:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-picklefield>=3.0.1:../../www/py-django-picklefield

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
