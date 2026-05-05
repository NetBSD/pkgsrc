# $NetBSD: Makefile,v 1.100 2026/05/05 15:20:13 ktnb Exp $

DISTNAME=	v3.3.0
PKGNAME=	dillo-${DISTNAME:S/v//}
CATEGORIES=	www
MASTER_SITES=	https://git.sr.ht/~dillo/dillo/archive/
DIST_SUBDIR=	dillo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dillo-browser.org/
COMMENT=	Very small and fast graphical web-browser
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
# x11/fltk is >1.3, which requires this flag
CONFIGURE_ARGS+=	--enable-experimental-fltk
USE_FEATURES+=		snprintf vsnprintf
USE_TOOLS+=		aclocal autoconf automake autoreconf gmake perl:run

DEPENDS+=	wget-[0-9]*:../../net/wget

REPLACE_PERL+=	dillo-install-hyphenation

PKG_SYSCONFSUBDIR=	dillo
EGDIR=			${PREFIX}/share/examples/dillo
CONF_FILES=		${EGDIR}/dillorc ${PKG_SYSCONFDIR}/dillorc
CONF_FILES+=		${EGDIR}/dpidrc ${PKG_SYSCONFDIR}/dpidrc
CONF_FILES+=		${EGDIR}/keysrc ${PKG_SYSCONFDIR}/keysrc
CONF_FILES+=		${EGDIR}/domainrc ${PKG_SYSCONFDIR}/domainrc

INSTALLATION_DIRS=	share/doc/dillo ${EGDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

.include "options.mk"

WRKSRC=		${WRKDIR}/dillo-${DISTNAME}

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${PREFIX}/share/doc/dillo

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
