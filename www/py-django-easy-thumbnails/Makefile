# $NetBSD: Makefile,v 1.2 2014/01/20 15:45:14 wiz Exp $

DISTNAME=	easy-thumbnails-1.2
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/e/easy-thumbnails/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/SmileyChris/easy-thumbnails
COMMENT=	Easy thumbnails for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 1.2
EGG_NAME=	${DISTNAME:S/-/_/}

USE_LANGUAGES=		# empty

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
