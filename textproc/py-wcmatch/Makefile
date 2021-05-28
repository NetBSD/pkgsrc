# $NetBSD: Makefile,v 1.1 2021/05/28 04:25:14 adam Exp $

DISTNAME=	wcmatch-8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wcmatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facelessuser/wcmatch
COMMENT=	Wildcard/glob file name matcher
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-bracex>=2.1.1:../../textproc/py-bracex

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
