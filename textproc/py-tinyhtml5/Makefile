# $NetBSD: Makefile,v 1.2 2026/03/06 13:04:37 adam Exp $

DISTNAME=	tinyhtml5-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tinyhtml5/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CourtBouillon/tinyhtml5
COMMENT=	HTML parser based on the WHATWG HTML specification
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-webencodings>=0.5.1:../../textproc/py-webencodings

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
