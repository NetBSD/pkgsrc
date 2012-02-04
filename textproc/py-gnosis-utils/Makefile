# $NetBSD: Makefile,v 1.11 2012/02/04 05:46:10 obache Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
