# $NetBSD: Makefile,v 1.22 2008/11/10 17:21:38 wiz Exp $

DISTNAME=	x3270-3213
PKGNAME=	x3270-3.2.13
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://www.geocities.com/SiliconValley/Peaks/7814/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Peaks/7814/
COMMENT=	3270 Terminal emulator

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/x3270-3.2
USE_IMAKE=	yes

FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/misc

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
