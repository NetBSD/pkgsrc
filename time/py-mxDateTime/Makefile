# $NetBSD: Makefile,v 1.26 2008/06/12 02:14:53 joerg Exp $
#

DISTNAME=	egenix-mx-base-2.0.6
PKGNAME=	${PYPKGPREFIX}-mxDateTime-2.0.6
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	http://www.egenix.com/files/python/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.egenix.com/files/python/mxDateTime.html
COMMENT=	Python extension that provides types and conversions for dates

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYTHON_VERSIONS_ACCEPTED= 25 24 23 21

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
