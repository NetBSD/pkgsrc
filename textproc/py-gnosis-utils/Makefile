# $NetBSD: Makefile,v 1.13 2012/10/25 06:56:50 asau Exp $
#

DISTNAME=	Gnosis_Utils-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	http://gnosis.cx/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnosis.cx/download/
COMMENT=	Classes for working with XML
LICENSE=	public-domain

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LANGUAGES=	#none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
