# $NetBSD: Makefile,v 1.11 2018/08/19 10:54:36 adam Exp $

DISTNAME=	channels-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/channels/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/channels
COMMENT=	Brings event-driven capabilities to Django with a channel system
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-asgiref>=2.3:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-daphne>=2.2:../../www/py-daphne
DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
