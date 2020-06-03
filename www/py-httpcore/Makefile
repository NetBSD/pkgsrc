# $NetBSD: Makefile,v 1.1 2020/06/03 14:18:43 adam Exp $

DISTNAME=	httpcore-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpcore/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/encode/httpcore
COMMENT=	Minimal low-level HTTP client
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-h11>=0.8.0:../../www/py-h11
DEPENDS+=	${PYPKGPREFIX}-h2>=3.0:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-sniffio>=1.0.0:../../misc/py-sniffio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
