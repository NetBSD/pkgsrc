# $NetBSD: Makefile,v 1.3 2025/04/14 11:57:58 adam Exp $

DISTNAME=	cmarkgfm-2024.11.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmarkgfm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/theacodes/cmarkgfm
COMMENT=	Minimal bindings to GitHub's fork of cmark
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.15.0:../../devel/py-cffi

.include "../../lang/python/wheel.mk"
.include "../../textproc/cmark-gfm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
