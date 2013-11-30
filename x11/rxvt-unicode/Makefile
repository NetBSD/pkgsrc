# $NetBSD: Makefile,v 1.49 2013/11/30 23:24:10 morr Exp $

DISTNAME=	rxvt-unicode-9.19
CATEGORIES=	x11
MASTER_SITES=	http://dist.schmorp.de/rxvt-unicode/ \
		http://dist.schmorp.de/rxvt-unicode/Attic/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/rxvt-unicode.html
COMMENT=	Clone of rxvt supporting Xft fonts and Unicode
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_FEATURES+=	snprintf

CONFIGURE_ENV+=		ac_cv_path_TIC=no

CONFIGURE_ARGS+=	--enable-256-color

INSTALLATION_DIRS+=	share/doc/rxvt-unicode share/examples/rxvt-unicode

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.FAQ \
		${DESTDIR}${PREFIX}/share/doc/rxvt-unicode
.for t in rxvt-unicode.termcap rxvt-unicode.terminfo
	${INSTALL_DATA} ${WRKSRC}/doc/etc/${t} \
		${DESTDIR}${PREFIX}/share/examples/rxvt-unicode
.endfor

.include "options.mk"

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
