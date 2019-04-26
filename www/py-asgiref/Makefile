# $NetBSD: Makefile,v 1.12 2019/04/26 13:14:20 maya Exp $

DISTNAME=	asgiref-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asgiref/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/asgiref
COMMENT=	Contains various reference ASGI implementations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-async-timeout>=2.0.0:../../devel/py-async-timeout

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
