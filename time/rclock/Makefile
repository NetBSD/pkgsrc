# $NetBSD: Makefile,v 1.8 2006/02/05 23:11:10 joerg Exp $

DISTNAME=		rxvt-2.6.0
PKGNAME=		rclock-2.6.0
PKGREVISION=		1
CATEGORIES=		x11 time
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/file/managers/mc/rxvt/}  \
			ftp://ftp.nuclecu.unam.mx/linux/local/rxvt/  \
			ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin.X11/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Analog clock for X w/appointment reminder and mail notification

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		clock

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
