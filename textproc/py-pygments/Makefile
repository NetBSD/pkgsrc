# $NetBSD: Makefile,v 1.51 2023/11/22 10:07:37 adam Exp $

DISTNAME=	pygments-2.17.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygments/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pygments.org/
COMMENT=	Python syntax highlighter
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-wcag-contrast-ratio-[0-9]*:../../graphics/py-wcag-contrast-ratio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pygmentize pygmentize-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
