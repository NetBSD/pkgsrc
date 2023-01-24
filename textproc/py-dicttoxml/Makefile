# $NetBSD: Makefile,v 1.8 2023/01/24 13:01:54 adam Exp $

DISTNAME=	dicttoxml-1.7.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dicttoxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quandyfactory/dicttoxml
COMMENT=	Library for simple XML serialization
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
