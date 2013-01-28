# $NetBSD: Makefile,v 1.1 2013/01/28 21:15:26 adam Exp $

DISTNAME=	easy-thumbnails-1.2
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/e/easy-thumbnails/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/SmileyChris/easy-thumbnails
COMMENT=	Easy thumbnails for Django
LICENSE=	modified-bsd

PYDISTUTILSPKG=		yes
USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
