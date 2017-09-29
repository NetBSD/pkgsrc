# $NetBSD: Makefile,v 1.1 2017/09/29 21:20:16 joerg Exp $

DISTNAME=	ramlfications-0.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ramlfications/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ramlfications.readthedocs.org/
COMMENT=	Python RAML parser
LICENSE=	apache-2.0

# Test dependencies
BUILD_DEPENDS+=		${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
BUILD_DEPENDS+=		${PYPKGPREFIX}-termcolor-[0-9]*:../../devel/py-termcolor
BUILD_DEPENDS+=		${PYPKGPREFIX}-test-localserver-[0-9]*:../../devel/py-test-localserver
BUILD_DEPENDS+=		${PYPKGPREFIX}-jsonref-[0-9]*:../../textproc/py-jsonref
BUILD_DEPENDS+=		${PYPKGPREFIX}-markdown2-[0-9]*:../../textproc/py-markdown2
BUILD_DEPENDS+=		${PYPKGPREFIX}-xmltodict-[0-9]*:../../textproc/py-xmltodict

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
