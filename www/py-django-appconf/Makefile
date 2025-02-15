# $NetBSD: Makefile,v 1.12 2025/02/15 16:12:49 adam Exp $

DISTNAME=	django-appconf-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-appconf/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/django-compressor/django-appconf
COMMENT=	Helper class for handling configuration defaults of Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=4:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
