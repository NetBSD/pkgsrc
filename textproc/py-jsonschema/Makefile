# $NetBSD: Makefile,v 1.8 2017/01/03 13:23:04 jperkin Exp $

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
	${MV} ${DESTDIR}${PREFIX}/bin/jsonschema ${DESTDIR}${PREFIX}/bin/jsonschema${PYVERSSUFFIX} || ${TRUE}
	${RM} -r -f ${DESTDIR}${PREFIX}${PYSITELIB}/jsonschema/__pycache__

.include "../../mk/bsd.pkg.mk"
