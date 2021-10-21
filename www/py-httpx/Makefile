# $NetBSD: Makefile,v 1.15 2021/10/21 13:16:15 adam Exp $

DISTNAME=	httpx-0.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/encode/httpx
COMMENT=	The next generation HTTP client
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-charset-normalizer-[0-9]*:../../converters/py-charset-normalizer
DEPENDS+=	${PYPKGPREFIX}-httpcore>=0.13.3:../../www/py-httpcore
DEPENDS+=	${PYPKGPREFIX}-rfc3986>=1.3:../../www/py-rfc3986
DEPENDS+=	${PYPKGPREFIX}-sniffio-[0-9]*:../../misc/py-sniffio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 36 # py-httpcore, py-anyio, py-uvloop

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} httpx httpx-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
