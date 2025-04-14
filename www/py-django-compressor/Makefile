# $NetBSD: Makefile,v 1.7 2025/04/14 13:30:02 adam Exp $

DISTNAME=	django_compressor-4.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-compressor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/django-compressor/django-compressor/
COMMENT=	Compresses linked and inline javascript or CSS into single cached file
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-appconf>=1.0.3:../../www/py-django-appconf
DEPENDS+=	${PYPKGPREFIX}-rcssmin>=1.1.2:../../www/py-rcssmin
DEPENDS+=	${PYPKGPREFIX}-rjsmin>=1.2.2:../../www/py-rjsmin

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
