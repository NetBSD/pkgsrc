# $NetBSD: Makefile,v 1.29 2026/05/06 08:37:55 adam Exp $

DISTNAME=	ujson-5.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/ujson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ultrajson/ultrajson
COMMENT=	Ultra fast JSON encoder and decoder for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm

USE_LANGUAGES=	c c++

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/src/ujson/python/version.h

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
