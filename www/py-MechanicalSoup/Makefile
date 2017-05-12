# $NetBSD: Makefile,v 1.1 2017/05/12 10:02:13 wiz Exp $

DISTNAME=	MechanicalSoup-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MechanicalSoup/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hickford/MechanicalSoup
COMMENT=	Library for automating interaction with websites
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
