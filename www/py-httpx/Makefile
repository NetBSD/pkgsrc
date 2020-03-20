# $NetBSD: Makefile,v 1.5 2020/03/20 07:43:06 adam Exp $

DISTNAME=	httpx-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/encode/httpx
COMMENT=	The next generation HTTP client
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-chardet>=3.0.0:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-h11>=0.8.0:../../www/py-h11
DEPENDS+=	${PYPKGPREFIX}-h2>=3.0:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-hstspreload-[0-9]*:../../www/py-hstspreload
DEPENDS+=	${PYPKGPREFIX}-idna>=2.0:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-rfc3986>=1.3:../../www/py-rfc3986
DEPENDS+=	${PYPKGPREFIX}-sniffio>=1.0.0:../../misc/py-sniffio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
