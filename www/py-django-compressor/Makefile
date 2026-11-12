# $NetBSD: Makefile,v 1.9 2026/11/12 11:38:10 adam Exp $

DISTNAME=	django_compressor-4.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-compressor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/django-compressor/django-compressor
COMMENT=	Compresses linked and inline javascript or CSS into single cached file
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=5.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-appconf>=1.0.3:../../www/py-django-appconf
DEPENDS+=	${PYPKGPREFIX}-rcssmin>=1.2.1:../../www/py-rcssmin
DEPENDS+=	${PYPKGPREFIX}-rjsmin>=1.2.4:../../www/py-rjsmin

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
