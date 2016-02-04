# $NetBSD: Makefile,v 1.88 2016/02/04 12:13:31 wiz Exp $

DISTNAME=	midori_0.5.11_all_
PKGNAME=	${DISTNAME:S/_all_//:S/_/-/}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://midori-browser.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://midori-browser.org/
COMMENT=	Lightweight web browser using WebKit
LICENSE=	gnu-lgpl-v2.1
EXTRACT_SUFX=	.tar.bz2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

HAS_CONFIGURE=	yes
USE_CMAKE=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--disable-zeitgeist
CMAKE_ARGS+=		-DUSE_ZEITGEIST=OFF
CMAKE_ARGS+=		-DPREFIX=${PREFIX}

CHECK_PORTABILITY_SKIP+= win32/old/x86-mingw32-opensuse/install.sh
CHECK_PORTABILITY_SKIP+= win32/makedist/makedist.midori

BUILD_DEPENDS+=		librsvg>=2.18:../../graphics/librsvg

DEPENDS+=		gnome-themes-[0-9]*:../../x11/gnome-themes

EGDIR=			${PREFIX}/share/examples/midori
OWN_DIRS=		${PKG_SYSCONFDIR}/xdg/midori
CONF_FILES=		${EGDIR}/search ${PKG_SYSCONFDIR}/xdg/midori/search

.include "../../mk/bsd.prefs.mk"

OWN_DIRS+=	${PKG_SYSCONFDIR}/xdg/midori/extensions/adblock
CONF_FILES+=	${EGDIR}/extensions/adblock/config \
		${PKG_SYSCONFDIR}/xdg/midori/extensions/adblock/config

CONFIGURE_ENV=	VALAC=${VALAC}

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
#.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala= build
.include "../../lang/vala/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
