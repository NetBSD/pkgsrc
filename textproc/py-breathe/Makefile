# $NetBSD: Makefile,v 1.8 2023/11/07 22:38:05 wiz Exp $

DISTNAME=	breathe-4.35.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/breathe/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/breathe-doc/breathe
COMMENT=	Sphinx plugin providing integrated Doxygen output
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-sphinx>=4.0:../../textproc/py-sphinx

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} breathe-apidoc breathe-apidoc-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
