# $NetBSD: Makefile,v 1.11 2006/07/22 04:46:20 rillig Exp $
#

DISTNAME=		rxvt-unicode-7.5
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://dist.schmorp.de/rxvt-unicode/ \
			http://dist.schmorp.de/rxvt-unicode/Attic/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://software.schmorp.de/pkg/rxvt-unicode
COMMENT=		rxvt clone supporting Xft fonts and Unicode

BROKEN_IN=		pkgsrc-2006Q1

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
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
