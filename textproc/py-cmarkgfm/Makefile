# $NetBSD: Makefile,v 1.1 2023/06/04 03:02:29 markd Exp $

DISTNAME=	cmarkgfm-2022.10.27
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmarkgfm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/theacodes/cmarkgfm
COMMENT=	Minimal bindings to GitHub's fork of cmark
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.15.0:../../devel/py-cffi

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../textproc/cmark-gfm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
