# $NetBSD: Makefile,v 1.2 2020/05/07 09:29:04 adam Exp $

DISTNAME=	demjson-2.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/demjson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dmeranda/demjson
COMMENT=	Encoder, decoder, and lint/validator for JSON compliant with RFC 7159
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jsonlint jsonlint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
