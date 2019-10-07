# $NetBSD: Makefile,v 1.17 2019/10/07 20:28:57 adam Exp $

DISTNAME=	channels-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/channels/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/channels
COMMENT=	Brings event-driven capabilities to Django with a channel system
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-asgiref>=3.0:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-daphne>=2.3:../../www/py-daphne
DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
