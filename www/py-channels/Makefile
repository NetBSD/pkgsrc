# $NetBSD: Makefile,v 1.4 2017/09/15 12:49:07 adam Exp $

DISTNAME=	channels-1.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/channels/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/channels
COMMENT=	Brings event-driven capabilities to Django with a channel system
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-asgiref>=1.1:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-daphne>=1.3:../../www/py-daphne

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
