# $NetBSD: Makefile,v 1.18 2024/05/06 08:40:33 jperkin Exp $
#

DISTNAME=		ggiterm-0.7.1
PKGREVISION=		7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggiterm/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ggiterm.sourceforge.net/
COMMENT=		Libggi-based terminal emulator

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PTHREAD_AUTO_VARS=	yes

CONFIGURE_ARGS+=	--disable-freetypetest

INSTALLATION_DIRS=	share/doc/ggiterm

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ggiterm
	${INSTALL_DATA} ${WRKSRC}/ggiterm.termcap ${DESTDIR}${PREFIX}/share/doc/ggiterm
	${INSTALL_DATA} ${WRKSRC}/ggiterm.terminfo ${DESTDIR}${PREFIX}/share/doc/ggiterm

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libggiwmh/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
