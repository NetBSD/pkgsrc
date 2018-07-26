# $NetBSD: Makefile,v 1.1 2018/07/26 13:55:30 jaapb Exp $

DISTNAME=	pybtex-0.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybtex/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://pybtex.org/
COMMENT=	BibTeX-compatible bibliography processor written in Python
LICENSE=	mit

BUILD_DEPENDS+=		py[0-9]*-latexcodec-[0-9]*:../../print/py-latexcodec
BUILD_DEPENDS+=		py[0-9]*-yaml-[0-9]*:../../textproc/py-yaml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
