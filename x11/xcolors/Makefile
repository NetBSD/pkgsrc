# $NetBSD: Makefile,v 1.16 2006/12/27 13:37:43 joerg Exp $

DISTNAME=	xcolors
PKGNAME=	xcolors-1.3
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tut.ac.jp/X11/X11R6/contrib/programs/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display all (ok, most of) the colors in the universe

WRKSRC=		${WRKDIR}/xcolors
USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
