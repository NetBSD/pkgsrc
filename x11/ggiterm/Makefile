# $NetBSD: Makefile,v 1.6 2008/06/20 01:09:44 joerg Exp $
#

DISTNAME=		ggiterm-0.7.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggiterm/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ggiterm.sourceforge.net/
COMMENT=		Libggi-based terminal emulator

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PTHREAD_AUTO_VARS=	yes

INSTALLATION_DIRS=	share/doc/ggiterm

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ggiterm
	${INSTALL_DATA} ${WRKSRC}/ggiterm.termcap ${DESTDIR}${PREFIX}/share/doc/ggiterm
	${INSTALL_DATA} ${WRKSRC}/ggiterm.terminfo ${DESTDIR}${PREFIX}/share/doc/ggiterm

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libggiwmh/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
