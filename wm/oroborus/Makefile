# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:55 jlam Exp $
#

DISTNAME=	oroborus_2.0.12-1
PKGNAME=	${DISTNAME:S/_/-/:C/-.$//}
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://www.oroborus.org/debian/dists/sid/main/source/x11/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oroborus.org/
COMMENT=	Small and simple window manager for X

WRKSRC=         ${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
