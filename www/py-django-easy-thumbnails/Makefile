# $NetBSD: Makefile,v 1.7 2018/01/11 13:50:39 adam Exp $

DISTNAME=	easy-thumbnails-2.5
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/easy-thumbnails/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/SmileyChris/easy-thumbnails/
COMMENT=	Easy thumbnails for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
