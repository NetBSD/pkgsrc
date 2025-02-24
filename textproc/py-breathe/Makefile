# $NetBSD: Makefile,v 1.13 2025/02/24 09:13:50 wiz Exp $

DISTNAME=	breathe-4.36.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/breathe/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/breathe-doc/breathe
COMMENT=	Sphinx plugin providing integrated Doxygen output
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-sphinx>=7.2:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-sphinx

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} breathe-apidoc breathe-apidoc-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
