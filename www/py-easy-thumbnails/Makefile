# $NetBSD: Makefile,v 1.7 2023/10/10 16:37:09 adam Exp $

DISTNAME=	easy-thumbnails-2.8.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/easy-thumbnails/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/SmileyChris/easy-thumbnails
COMMENT=	Easy thumbnails for Django
LICENSE=	modified-bsd

PREV_PKGPATH=	www/py-djangoeasy-thumbnails

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
