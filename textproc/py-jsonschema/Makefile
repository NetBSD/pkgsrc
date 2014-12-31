# $NetBSD: Makefile,v 1.1 2014/12/31 13:18:58 bsiegert Exp $

DISTNAME=	jsonschema-2.4.0
CATEGORIES=	textproc python
MASTER_SITES=	https://pypi.python.org/packages/source/j/jsonschema/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Julian/jsonschema
COMMENT=	Implementation of JSON Schema for Python
LICENSE=	modified-bsd

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/egg.mk"

post-install:
	mv ${DESTDIR}${PREFIX}/bin/jsonschema ${DESTDIR}${PREFIX}/bin/jsonschema${PYVERSSUFFIX}

.include "../../mk/bsd.pkg.mk"
