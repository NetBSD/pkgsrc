# $NetBSD: Makefile,v 1.7 1999/01/30 23:18:58 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1997/03/12 08:21:35 asami Exp
#

DISTNAME=	xneko
PKGNAME=	xneko-4.4
CATEGORIES=	x11 games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/bsd-sources/4.4BSD-Lite/usr/src/games/

MAINTAINER=	packages@netbsd.org

USE_X11BASE=	yes
IGNOREFILES=	${DISTFILES}
WRKSRC=		${WRKDIR}/pub/bsd-sources/4.4BSD-Lite/usr/src/games/xneko

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

.include "../../mk/bsd.pkg.mk"
