# $NetBSD: Makefile,v 1.13 2025/04/14 13:30:01 adam Exp $

DISTNAME=	django-appconf-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
