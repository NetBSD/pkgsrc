# $NetBSD: Makefile,v 1.1 2022/10/26 13:25:20 adam Exp $

DISTNAME=	demjson3-3.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/demjson3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nielstron.github.io/demjson3/
COMMENT=	Encoder, decoder, and lint/validator for JSON compliant with RFC 7159
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jsonlint jsonlint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
