# $NetBSD: Makefile,v 1.9 2004/05/07 01:14:50 xtraeme Exp $
#

DISTNAME=	oroborus_2.0.12-1
PKGNAME=	${DISTNAME:S/_/-/:C/-.$//}
CATEGORIES=	wm x11
MASTER_SITES=	http://www.oroborus.org/debian/dists/sid/main/source/x11/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.oroborus.org/
COMMENT=	Small and simple window manager for X

WRKSRC=         ${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
