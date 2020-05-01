# $NetBSD: Makefile,v 1.1 2020/05/01 17:52:29 nia Exp $

DISTNAME=	demjson-2.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/demjson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dmeranda/demjson
COMMENT=	Encoder, decoder, and lint/validator for JSON compliant with RFC 7159
LICENSE=	gnu-lgpl-v3

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jsonlint \
	    ${DESTDIR}${PREFIX}/bin/jsonlint-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
