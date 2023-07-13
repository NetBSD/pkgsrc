# $NetBSD: Makefile,v 1.9 2023/07/13 10:03:26 wiz Exp $

DISTNAME=	django-appconf-1.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-appconf/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/django-compressor/django-appconf/
COMMENT=	Helper class for handling configuration defaults of Django
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
