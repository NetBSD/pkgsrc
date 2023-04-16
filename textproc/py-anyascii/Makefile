# $NetBSD: Makefile,v 1.2 2023/04/16 07:36:06 wiz Exp $

DISTNAME=	anyascii-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_PYPI:=a/anyascii/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anyascii/anyascii
COMMENT=	Intelligent Unicode to ASCII conversion
LICENSE=	isc

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
