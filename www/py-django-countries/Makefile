# $NetBSD: Makefile,v 1.21 2026/09/03 09:22:39 adam Exp $

DISTNAME=	django_countries-9.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-countries/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/SmileyChris/django-countries
COMMENT=	Provides a country field for Django models
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.9.6:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-asgiref>=0:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	django_countries/data.py
REPLACE_PYTHON+=	django_countries/makesprite.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
