# $NetBSD: Makefile,v 1.15 2020/07/09 08:46:50 adam Exp $

DISTNAME=	django-cors-headers-3.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-cors-headers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adamchainz/django-cors-headers
COMMENT=	Django application for handling headers required for CORS
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django>=2.0:../../www/py-django2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # since 3.1.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
