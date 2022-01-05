# $NetBSD: Makefile,v 1.4 2022/01/05 15:41:26 wiz Exp $

DISTNAME=	ramlfications-0.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ramlfications/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ramlfications.readthedocs.org/
COMMENT=	Python RAML parser
LICENSE=	apache-2.0

TEST_DEPENDS+=		${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
TEST_DEPENDS+=		${PYPKGPREFIX}-termcolor-[0-9]*:../../devel/py-termcolor
TEST_DEPENDS+=		${PYPKGPREFIX}-test-localserver-[0-9]*:../../devel/py-test-localserver
TEST_DEPENDS+=		${PYPKGPREFIX}-jsonref-[0-9]*:../../textproc/py-jsonref
TEST_DEPENDS+=		${PYPKGPREFIX}-xmltodict-[0-9]*:../../textproc/py-xmltodict

PYTHON_VERSIONED_DEPENDENCIES+=	markdown:test

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
