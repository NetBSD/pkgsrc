# $NetBSD: Makefile,v 1.8 2018/04/13 11:13:32 adam Exp $

DISTNAME=	channels-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/channels/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/channels
COMMENT=	Brings event-driven capabilities to Django with a channel system
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-asgiref>=2.1:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-daphne>=2.0:../../www/py-daphne

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
