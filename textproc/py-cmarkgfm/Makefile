# $NetBSD: Makefile,v 1.2 2025/02/12 09:26:42 adam Exp $

DISTNAME=	cmarkgfm-2024.11.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmarkgfm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/theacodes/cmarkgfm
COMMENT=	Minimal bindings to GitHub's fork of cmark
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.15.0:../../devel/py-cffi

.include "../../lang/python/wheel.mk"
.include "../../textproc/cmark-gfm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
