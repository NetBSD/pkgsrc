# $NetBSD: Makefile,v 1.9 1999/07/05 00:34:09 kim Exp $
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
MANCOMPRESSED_IF_MANZ=	yes

PLIST_SRC=	${WRKDIR}/PLIST

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@for OPT in ${MANINSTALL} x; do \
	  case $$OPT in \
	    catinstall) ${ECHO} man/cat6/xneko.0 >>${PLIST_SRC};; \
	    maninstall) ${ECHO} man/man6/xneko.6 >>${PLIST_SRC};; \
	  esac; \
	done

.include "../../mk/bsd.pkg.mk"
