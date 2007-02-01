# $NetBSD: Makefile,v 1.10 2007/02/01 23:57:07 joerg Exp $

DISTNAME=		rxvt-2.6.0
PKGNAME=		rclock-2.6.0
PKGREVISION=		1
CATEGORIES=		x11 time
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/file/managers/mc/rxvt/}  \
			ftp://ftp.nuclecu.unam.mx/linux/local/rxvt/  \
			ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin.X11/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Analog clock for X w/appointment reminder and mail notification

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		clock

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
