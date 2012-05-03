# $NetBSD: Makefile,v 1.20 2012/05/03 09:55:32 obache Exp $

DISTNAME=	xcolors
PKGNAME=	xcolors-1.3
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tut.ac.jp/X11/X11R6/contrib/programs/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display all (ok, most of) the colors in the universe

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/xcolors
USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
DEPENDS+=	rgb>=1.0.1:../../x11/rgb
CPPFLAGS+=	-DRGB_TXT=\"${PREFIX}/share/X11/rgb.txt\"
.else
CPPFLAGS+=	-DRGB_TXT=\"${X11BASE}/lib/X11/rgb.txt\"
.endif

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
