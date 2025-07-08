# $NetBSD: Makefile,v 1.4 2025/07/08 15:55:42 adam Exp $

DISTNAME=	anyascii-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_PYPI:=a/anyascii/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anyascii/anyascii
COMMENT=	Intelligent Unicode to ASCII conversion
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
