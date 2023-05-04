# $NetBSD: Makefile,v 1.1 2023/05/04 06:54:35 adam Exp $

DISTNAME=	requests-wsgi-adapter-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-wsgi-adapter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seanbrant/requests-wsgi-adapter
COMMENT=	WSGI Transport Adapter for Requests
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-requests>=1.0:../../devel/py-requests

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
