# $NetBSD: Makefile,v 1.2 2018/11/20 11:52:43 adam Exp $

DISTNAME=	jsonref-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonref/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gazpachoking/jsonref
COMMENT=	JSON References for Python
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX} tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
