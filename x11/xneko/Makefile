# $NetBSD: Makefile,v 1.5 1998/05/28 08:29:42 frueauf Exp $
# FreeBSD Id: Makefile,v 1.6 1997/03/12 08:21:35 asami Exp
#

DISTNAME=	xneko
PKGNAME=	xneko-4.4
CATEGORIES=	x11 games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/bsd-sources/4.4BSD-Lite/usr/src/games/

MAINTAINER=	packages@netbsd.org

USE_X11=	yes
IGNOREFILES=	${DISTFILES}
WRKSRC=		${WRKDIR}/pub/bsd-sources/4.4BSD-Lite/usr/src/games/xneko

# Do not list MAN/CAT pages here. It will confuse if MANZ is set.
# The pkg uses BSD-style-Makefiles itself, so it does the right thing.

.include "../../mk/bsd.pkg.mk"
