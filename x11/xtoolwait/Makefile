# $NetBSD: Makefile,v 1.10 2008/07/14 12:56:20 joerg Exp $
#

DISTNAME=	xtoolwait-1.3
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.hacom.nl/~richard/software/

MAINTAINER=	minoura@NetBSD.org
HOMEPAGE=	http://www.hacom.nl/~richard/software/xtoolwait.html
COMMENT=	Free implementation of SunOS toolwait(1)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
