# $NetBSD: Makefile,v 1.6 2006/02/04 10:47:50 wiz Exp $
#

DISTNAME=		rxvt-unicode-7.2
CATEGORIES=		x11
MASTER_SITES=		http://dist.schmorp.de/rxvt-unicode/ \
			http://dist.schmorp.de/rxvt-unicode/Attic/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://software.schmorp.de/pkg/rxvt-unicode
COMMENT=		rxvt clone supporting Xft fonts and Unicode

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c++
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--enable-transparency	\
			--enable-menubar	\
			--enable-xpm-background	\
			--enable-xgetdefault	\
			--with-term=rxvt	\
			--enable-24bit

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rxvt-unicode
	${INSTALL_DATA} ${WRKSRC}/README.FAQ ${PREFIX}/share/doc/rxvt-unicode

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
