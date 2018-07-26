# $NetBSD: Makefile,v 1.2 2018/07/26 14:01:57 jaapb Exp $

DISTNAME=	pybtex-0.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION= 1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybtex/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://pybtex.org/
COMMENT=	BibTeX-compatible bibliography processor written in Python
LICENSE=	mit

DEPENDS+=		py[0-9]*-latexcodec-[0-9]*:../../print/py-latexcodec
DEPENDS+=		py[0-9]*-yaml-[0-9]*:../../textproc/py-yaml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
