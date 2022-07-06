# $NetBSD: Makefile,v 1.23 2022/07/06 15:30:19 adam Exp $

DISTNAME=	channels-3.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/channels/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/channels
COMMENT=	Brings event-driven capabilities to Django with a channel system
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-asgiref>=3.3.1:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-daphne>=3.0:../../www/py-daphne
DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
