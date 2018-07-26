# $NetBSD: Makefile,v 1.3 2018/07/26 14:20:29 jaapb Exp $

DISTNAME=	pybtex-0.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION= 2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybtex/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://pybtex.org/
COMMENT=	BibTeX-compatible bibliography processor written in Python
LICENSE=	mit

DEPENDS+=		${PYPKGPREFIX}-latexcodec-[0-9]*:../../print/py-latexcodec
DEPENDS+=		${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
