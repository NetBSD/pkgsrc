# $NetBSD: Makefile,v 1.7 2004/01/20 12:27:35 agc Exp $
#

DISTNAME=	oroborus_2.0.12-1
PKGNAME=	${DISTNAME:S/_/-/:C/-.$//}
CATEGORIES=	wm x11
MASTER_SITES=	http://www.oroborus.org/debian/dists/sid/main/source/x11/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.oroborus.org/
COMMENT=	Small and simple window manager for X

WRKSRC=         ${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
