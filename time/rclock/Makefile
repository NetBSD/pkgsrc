# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:19 wiz Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/03/03 16:27:10 obrien Exp
#

DISTNAME=		rxvt-2.6.0
PKGNAME=		rclock-2.6.0
CATEGORIES=		x11 time
MASTER_SITES=		${MASTER_SITE_SUNSITE:=utils/file/managers/mc/rxvt/}  \
			ftp://ftp.nuclecu.unam.mx/linux/local/rxvt/  \
			ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin.X11/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
ALL_TARGET=		clock

.include "../../mk/bsd.pkg.mk"
