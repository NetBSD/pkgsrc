# $NetBSD: Makefile,v 1.2 2017/05/14 13:00:12 leot Exp $

DISTNAME=	MechanicalSoup-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MechanicalSoup/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hickford/MechanicalSoup
COMMENT=	Library for automating interaction with websites
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.4:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
