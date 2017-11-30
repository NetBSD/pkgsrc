# $NetBSD: Makefile,v 1.2 2017/11/30 08:01:48 adam Exp $

DISTNAME=	asgiref-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asgiref/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/asgiref/
COMMENT=	Contains various reference ASGI implementations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
