# $NetBSD: Makefile,v 1.18 2026/11/09 13:41:24 adam Exp $

DISTNAME=	fastjsonschema-2.22.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fastjsonschema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/horejsek/python-fastjsonschema
COMMENT=	Fastest Python implementation of JSON schema
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=0:../../devel/py-test-benchmark

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
