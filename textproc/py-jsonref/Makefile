# $NetBSD: Makefile,v 1.1 2017/09/29 13:47:27 joerg Exp $

DISTNAME=	jsonref-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonref/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gazpachoking/jsonref
COMMENT=	JSON References for Python
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX} tests.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
