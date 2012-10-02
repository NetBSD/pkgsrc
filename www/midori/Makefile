# $NetBSD: Makefile,v 1.48 2012/10/02 17:12:09 tron Exp $

DISTNAME=	midori-0.4.6
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://archive.xfce.org/src/apps/midori/0.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.twotoasts.de/index.php?/pages/midori_summary.html
COMMENT=	Lightweight web browser using WebKit
EXTRACT_SUFX=	.tar.bz2

HAS_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

CHECK_PORTABILITY_SKIP+= win32/x86-mingw32-opensuse/install.sh
CHECK_PORTABILITY_SKIP+= win32/makedist/makedist.midori

PYTHON_FOR_BUILD_ONLY=	yes

REPLACE_PYTHON=		waf wscript docs/api/wscript_build
REPLACE_PYTHON+=	tests/wscript_build extensions/wscript_build
REPLACE_PYTHON+=	icons/wscript_build midori/wscript_build

BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.4:../../textproc/py-docutils
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

# XXX stupid hack. python has a marshal.h that gets included before
# the local marshal.h
SUBST_CLASSES+=		marshal marshal2
SUBST_STAGE.marshal=	pre-configure
SUBST_MESSAGE.marshal=	Gross hack (part one) in progress
SUBST_FILES.marshal=	midori/midori-locationaction.c midori/midori-panel.c
SUBST_FILES.marshal+=	midori/midori-view.c midori/midori-searchaction.c
SUBST_FILES.marshal+=	midori/midori-browser.c
SUBST_FILES.marshal+=	katze/katze-array.c katze/katze-arrayaction.c
SUBST_SED.marshal=	-e 's/"marshal/"marshallocal/'
SUBST_STAGE.marshal2=	pre-configure
SUBST_MESSAGE.marshal2=	Gross hack (part two) in progress
SUBST_FILES.marshal2=	midori/wscript_build
SUBST_SED.marshal2=	-e s/\'marshal/\'marshallocal/

pre-configure:
	${MV} ${WRKSRC}/midori/marshal.list ${WRKSRC}/midori/marshallocal.list

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.libsoup24+=libsoup24>=2.26.0
.include "../../net/libsoup24/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala= build
.include "../../lang/vala016/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
