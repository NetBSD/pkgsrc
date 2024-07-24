# $NetBSD: Makefile,v 1.5 2024/07/24 06:50:28 adam Exp $

DISTNAME=	django_compressor-4.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-compressor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/django-compressor/django-compressor/
COMMENT=	Compresses linked and inline javascript or CSS into single cached file
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-appconf>=1.0.3:../../www/py-django-appconf
DEPENDS+=	${PYPKGPREFIX}-rcssmin>=1.1.2:../../www/py-rcssmin
DEPENDS+=	${PYPKGPREFIX}-rjsmin>=1.2.2:../../www/py-rjsmin

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
