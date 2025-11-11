# $NetBSD: Makefile,v 1.14 2025/11/11 10:46:31 adam Exp $

DISTNAME=	django_appconf-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-appconf/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/django-compressor/django-appconf
COMMENT=	Helper class for handling configuration defaults of Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=4:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
