# $NetBSD: Makefile,v 1.3 2023/07/05 20:13:20 wiz Exp $

DISTNAME=	anyascii-0.3.2
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
