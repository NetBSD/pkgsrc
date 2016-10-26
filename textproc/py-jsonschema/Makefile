# $NetBSD: Makefile,v 1.7 2016/10/26 13:44:17 joerg Exp $

DISTNAME=	jsonschema-2.5.1
PKGREVISION=	2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonschema/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Julian/jsonschema
COMMENT=	Implementation of JSON Schema for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-vcversioner-[0-9]*:../../devel/py-vcversioner

.include "../../lang/python/egg.mk"

post-install:
	mv ${DESTDIR}${PREFIX}/bin/jsonschema ${DESTDIR}${PREFIX}/bin/jsonschema${PYVERSSUFFIX}
	${RM} -r -f ${DESTDIR}${PREFIX}${PYSITELIB}/jsonschema/__pycache__

.include "../../mk/bsd.pkg.mk"
