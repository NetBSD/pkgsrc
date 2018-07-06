# $NetBSD: Makefile,v 1.3 2018/07/06 11:17:42 adam Exp $

DISTNAME=	django-cors-headers-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-cors-headers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ottoyiu/django-cors-headers
COMMENT=	Django application for handling headers required for CORS
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
