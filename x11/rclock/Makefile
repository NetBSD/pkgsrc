# $NetBSD: Makefile,v 1.5 1998/04/20 11:56:35 frueauf Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/03/03 16:27:10 obrien Exp
#

DISTNAME=		rxvt-2.20
PKGNAME=		rclock-2.20
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SUNSITE}  \
			ftp://ftp.nuclecu.unam.mx/linux/local/rxvt/  \
			ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin.X11/
MASTER_SITE_SUBDIR=	utils/file/managers/mc/rxvt
#MASTER_SITE_SUBDIR=	X11/xutils/terms

MAINTAINER=		packages@netbsd.org

CFLAGS+=		'-DMAIL_SPOOL=\"/var/mail/\"'
USE_X11=		yes
GNU_CONFIGURE=		yes
ALL_TARGET=		clock
MAN1=			rclock.1

.include "../../mk/bsd.pkg.mk"
