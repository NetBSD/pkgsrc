# $NetBSD: Makefile,v 1.5 2003/06/18 09:22:26 agc Exp $
#

DISTNAME=	oroborus_2.0.12-1
PKGNAME=	${DISTNAME:S/_/-/:C/-.$//}
WRKSRC=         ${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	wm x11
MASTER_SITES=	http://www.oroborus.org/debian/dists/sid/main/source/x11/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.oroborus.org/
COMMENT=	Small and simple window manager for X

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
