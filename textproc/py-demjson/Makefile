# $NetBSD: Makefile,v 1.4 2022/01/04 20:54:54 wiz Exp $

DISTNAME=	demjson-2.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/demjson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dmeranda/demjson
COMMENT=	Encoder, decoder, and lint/validator for JSON compliant with RFC 7159
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"

.if ${PYPKGPREFIX} != "py27"
pre-build:
	cd ${WRKSRC} && 2to3-${PYVERSSUFFIX} -w --no-diffs jsonlint demjson.py
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jsonlint jsonlint-${PYVERSSUFFIX} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
