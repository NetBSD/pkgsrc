# $NetBSD: Makefile,v 1.4 2016/08/28 15:48:35 wiz Exp $

DISTNAME=	jsonschema-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonschema/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Julian/jsonschema
COMMENT=	Implementation of JSON Schema for Python
LICENSE=	modified-bsd

.include "../../lang/python/egg.mk"

post-install:
	mv ${DESTDIR}${PREFIX}/bin/jsonschema ${DESTDIR}${PREFIX}/bin/jsonschema${PYVERSSUFFIX}

.include "../../mk/bsd.pkg.mk"
