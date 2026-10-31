# $NetBSD: Makefile,v 1.5 2026/10/31 13:21:16 wiz Exp $

DISTNAME=	cmarkgfm-2025.10.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmarkgfm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/theacodes/cmarkgfm
COMMENT=	Minimal bindings to GitHub's fork of cmark
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-cparser>=2.06:../../devel/py-cparser
DEPENDS+=	${PYPKGPREFIX}-cffi>=2.0.0:../../devel/py-cffi

.include "../../lang/python/wheel.mk"
.include "../../textproc/cmark-gfm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
