# $NetBSD: Makefile,v 1.20 2025/12/26 16:45:03 adam Exp $

DISTNAME=	django_countries-8.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-countries/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/SmileyChris/django-countries
COMMENT=	Provides a country field for Django models
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.9.6:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-asgiref-[0-9]*:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	django_countries/data.py
REPLACE_PYTHON+=	django_countries/makesprite.py

post-extract:
	${RM} -f -r ${WRKSRC}/django_countries/.mypy_cache

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
