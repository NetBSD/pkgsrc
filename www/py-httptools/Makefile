# $NetBSD: Makefile,v 1.10 2022/09/19 08:36:20 adam Exp $

DISTNAME=	httptools-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httptools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/httptools
COMMENT=	Collection of framework independent HTTP protocol utils
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
