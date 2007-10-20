# $NetBSD: Makefile,v 1.20 2007/10/20 06:11:25 obache Exp $
#

DISTNAME=		rxvt-unicode-8.3
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://dist.schmorp.de/rxvt-unicode/ \
			http://dist.schmorp.de/rxvt-unicode/Attic/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://software.schmorp.de/pkg/rxvt-unicode.html
COMMENT=		rxvt clone supporting Xft fonts and Unicode

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--enable-transparency	\
			--enable-menubar	\
			--enable-xpm-background	\
			--enable-xgetdefault	\
			--enable-24bit
CONFIGURE_ENV+=		ac_cv_path_TIC=no

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rxvt-unicode
	${INSTALL_DATA} ${WRKSRC}/README.FAQ ${PREFIX}/share/doc/rxvt-unicode
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rxvt-unicode
.for t in rxvt-unicode.termcap rxvt-unicode.terminfo
	${INSTALL_DATA} ${WRKSRC}/doc/etc/${t} ${PREFIX}/share/examples/rxvt-unicode
.endfor

.include "options.mk"

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
