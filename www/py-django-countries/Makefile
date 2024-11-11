# $NetBSD: Makefile,v 1.18 2024/11/11 07:29:18 wiz Exp $

DISTNAME=	django-countries-7.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-countries/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/SmileyChris/django-countries
COMMENT=	Provides a country field for Django models
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=48:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asgiref-[0-9]*:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
