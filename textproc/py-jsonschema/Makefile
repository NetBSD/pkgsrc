# $NetBSD: Makefile,v 1.5 2016/10/09 21:30:58 bsiegert Exp $

DISTNAME=	jsonschema-2.5.1
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
	${RM} -r -f ${DESTDIR}${PREFIX}${PYSITELIB}/jsonschema/__pycache__

.include "../../mk/bsd.pkg.mk"
