# $NetBSD: Makefile,v 1.4 2003/05/27 18:18:48 salo Exp $
#

DISTNAME=	oroborus_2.0.12-1
PKGNAME=	${DISTNAME:S/_/-/:C/-.$//}
WRKSRC=         ${WRKDIR}/${PKGNAME}
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
