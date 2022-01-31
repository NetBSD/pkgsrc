# $NetBSD: Makefile,v 1.3 2022/01/31 11:39:40 adam Exp $

DISTNAME=	breathe-4.32.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/breathe/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/michaeljones/breathe
COMMENT=	Sphinx plugin providing integrated Doxygen output
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-sphinx>=3.0:../../textproc/py-sphinx

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} breathe-apidoc breathe-apidoc-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
