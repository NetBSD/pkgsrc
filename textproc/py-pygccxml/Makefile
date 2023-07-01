# $NetBSD: Makefile,v 1.2 2023/07/01 08:46:13 wiz Exp $

DISTNAME=	pygccxml-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_WHEEL:=pygccxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CastXML/pygccxml
COMMENT=	Python package for easy C++ declarations navigation
LICENSE=	boost-license

USE_LANGUAGES=	# none
NO_BUILD=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
