# $NetBSD: Makefile,v 1.11 2009/05/11 21:21:25 zafer Exp $
#

DISTNAME=	xtoolwait-1.3
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}


MAINTAINER=	minoura@NetBSD.org
HOMEPAGE=	http://www.hacom.nl/~richard/software/xtoolwait.html
COMMENT=	Free implementation of SunOS toolwait(1)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
