# $NetBSD: Makefile,v 1.6 2003/08/28 20:05:22 xtraeme Exp $
#

DISTNAME=	oroborus_2.0.12-1
PKGNAME=	${DISTNAME:S/_/-/:C/-.$//}
WRKSRC=         ${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	wm x11
MASTER_SITES=	http://www.oroborus.org/debian/dists/sid/main/source/x11/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.oroborus.org/
COMMENT=	Small and simple window manager for X

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
