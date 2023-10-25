# $NetBSD: Makefile,v 1.2 2023/10/25 19:40:36 markd Exp $

DISTNAME=	django_compressor-4.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-compressor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/django-compressor/django-compressor/
COMMENT=	Compresses linked and inline javascript or CSS into single cached file
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-django-appconf>=1.0.3:../../www/py-django-appconf
DEPENDS+=	${PYPKGPREFIX}-rcssmin>=1.1.1:../../www/py-rcssmin
DEPENDS+=	${PYPKGPREFIX}-rjsmin>=1.2.1:../../www/py-rjsmin

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
