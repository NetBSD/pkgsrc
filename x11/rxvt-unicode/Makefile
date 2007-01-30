# $NetBSD: Makefile,v 1.17 2007/01/30 20:41:32 joerg Exp $
#

DISTNAME=		rxvt-unicode-8.1
CATEGORIES=		x11
MASTER_SITES=		http://dist.schmorp.de/rxvt-unicode/ \
			http://dist.schmorp.de/rxvt-unicode/Attic/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://software.schmorp.de/pkg/rxvt-unicode
COMMENT=		rxvt clone supporting Xft fonts and Unicode

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--enable-transparency	\
			--enable-menubar	\
			--enable-xpm-background	\
			--enable-xgetdefault	\
			--enable-24bit

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rxvt-unicode
	${INSTALL_DATA} ${WRKSRC}/README.FAQ ${PREFIX}/share/doc/rxvt-unicode

.include "options.mk"

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
