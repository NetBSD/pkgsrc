# $NetBSD: Makefile,v 1.1 2017/09/29 13:55:07 joerg Exp $

DISTNAME=	xmltodict-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xmltodict/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/martinblech/xmltodict
COMMENT=	Simplified XML parser library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
