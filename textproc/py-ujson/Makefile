# $NetBSD: Makefile,v 1.28 2026/03/30 08:11:50 wiz Exp $

DISTNAME=	ujson-5.12.0
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
