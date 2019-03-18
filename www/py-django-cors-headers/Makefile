# $NetBSD: Makefile,v 1.7 2019/03/18 12:37:51 adam Exp $

DISTNAME=	django-cors-headers-2.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-cors-headers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ottoyiu/django-cors-headers
COMMENT=	Django application for handling headers required for CORS
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
