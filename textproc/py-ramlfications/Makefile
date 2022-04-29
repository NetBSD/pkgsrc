# $NetBSD: Makefile,v 1.5 2022/04/29 23:17:52 wiz Exp $

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
TEST_DEPENDS+=		${PYPKGPREFIX}-jsonref-[0-9]*:../../textproc/py-jsonref
TEST_DEPENDS+=		${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
TEST_DEPENDS+=		${PYPKGPREFIX}-termcolor-[0-9]*:../../devel/py-termcolor
TEST_DEPENDS+=		${PYPKGPREFIX}-test-localserver-[0-9]*:../../devel/py-test-localserver
TEST_DEPENDS+=		${PYPKGPREFIX}-xmltodict-[0-9]*:../../textproc/py-xmltodict

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
