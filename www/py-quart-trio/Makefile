# $NetBSD: Makefile,v 1.1 2025/12/05 21:15:10 wiz Exp $

DISTNAME=	quart_trio-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/quart-trio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/quart-trio/
COMMENT=	Quart extension to provide trio support
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-hypercorn>=0.12.0:../../www/py-hypercorn
DEPENDS+=	${PYPKGPREFIX}-quart>=0.19:../../www/py-quart
DEPENDS+=	${PYPKGPREFIX}-trio>=0.19.0:../../devel/py-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

# as of 0.12.0
# 13 failed, 15 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
