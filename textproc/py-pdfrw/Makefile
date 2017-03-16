# $NetBSD: Makefile,v 1.1 2017/03/16 20:07:05 darcy Exp $

DISTNAME=	pdfrw-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pdfrw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pmaupin/pdfrw
COMMENT=	PDF file reader/writer pure Python library
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
