# $NetBSD: Makefile,v 1.3 2025/01/14 11:52:48 adam Exp $

DISTNAME=	typogrify-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typogrify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mintchaos/typogrify
COMMENT=	Filters to enhance web typography
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-smartypants>=1.8.3:../../textproc/py-smartypants
# no tests in the distfile
#TEST_DEPENDS+=	${PYPKGPREFIX}-invoke>=2.2.0:../../sysutils/py-invoke
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=1.0.0:../../devel/py-test-sugar

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	typogrify/packages/titlecase/__init__.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
