# $NetBSD: Makefile,v 1.3 2006/01/12 13:32:47 joerg Exp $
#

DISTNAME=		ggiterm-0.7.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggiterm/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ggiterm.sourceforge.net/
COMMENT=		Libggi-based terminal emulator

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PTHREAD_AUTO_VARS=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ggiterm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ggiterm
	${INSTALL_DATA} ${WRKSRC}/ggiterm.termcap ${PREFIX}/share/doc/ggiterm
	${INSTALL_DATA} ${WRKSRC}/ggiterm.terminfo ${PREFIX}/share/doc/ggiterm

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libggiwmh/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
