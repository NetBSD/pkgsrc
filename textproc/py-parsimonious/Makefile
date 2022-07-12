# $NetBSD: Makefile,v 1.3 2022/07/12 08:27:34 adam Exp $

DISTNAME=	parsimonious-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parsimonious/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erikrose/parsimonious
COMMENT=	The fastest pure-Python PEG parser I could muster
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-regex>=2022.3.15:../../textproc/py-regex
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=0:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
