# $NetBSD: Makefile,v 1.13 2019/07/06 23:00:04 adam Exp $

DISTNAME=	asgiref-3.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asgiref/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/asgiref
COMMENT=	Contains various reference ASGI implementations
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
