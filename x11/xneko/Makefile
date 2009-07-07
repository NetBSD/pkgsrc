# $NetBSD: Makefile,v 1.28 2009/07/07 17:10:46 joerg Exp $

DISTNAME=	xneko
PKGNAME=	xneko-4.4
PKGREVISION=	2
CATEGORIES=	x11 games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/bsd-sources/4.4BSD-Lite/usr/src/games/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Classic BSD4.4 cat-and-mouse

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pub/bsd-sources/4.4BSD-Lite/usr/src/games/xneko
MANCOMPRESSED_IF_MANZ=	yes

PLIST_SRC=	${WRKDIR}/PLIST

BUILD_DEFS+=	MANINSTALL

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/cat6 ${PKGMANDIR}/man6

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@for OPT in ${MANINSTALL} x; do \
	  case $$OPT in \
	    catinstall) ${ECHO} man/cat6/xneko.0 >>${PLIST_SRC};; \
	    maninstall) ${ECHO} man/man6/xneko.6 >>${PLIST_SRC};; \
	  esac; \
	done

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
