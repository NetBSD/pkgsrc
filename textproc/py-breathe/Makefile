# $NetBSD: Makefile,v 1.2 2022/01/30 07:29:04 wiz Exp $

DISTNAME=	breathe-4.31.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=b/breathe/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/michaeljones/breathe
COMMENT=	Sphinx plugin providing integrated Doxygen output
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx>=3:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv breathe-apidoc breathe-apidoc-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
