# $NetBSD: Makefile,v 1.22 2011/11/01 06:03:01 sbd Exp $

DISTNAME=	kdebase-runtime-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	x11
COMMENT=	Runtime requirements for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=off
CMAKE_ARGS+=	-DLIBLZMA_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.xz}/include
CMAKE_ARGS+=	-DLIBLZMA_LIBRARY:FILEPATH=${BUILDLINK_PREFIX.xz}/lib/liblzma.so

DEPENDS+=	htdig>=3.2.0:../../www/htdig-devel
DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons

USE_TOOLS+=		gmake

.include "options.mk"

SUBST_CLASSES+=		htdig paths
SUBST_STAGE.htdig=	post-patch
SUBST_MESSAGE.htdig=	Fix htdig paths.
SUBST_FILES.htdig=	khelpcenter/searchhandlers/khc_htsearch.pl
SUBST_SED.htdig=	-e s:/srv/www/cgi-bin:${PREFIX}/libexec/cgi-bin:

SUBST_FILES.paths=	kioslave/info/kde-info2html.conf
SUBST_SED.paths=	-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_STAGE.paths=	post-patch

REPLACE_PERL+= \
	khelpcenter/searchhandlers/khc_docbookdig.pl.cmake \
	khelpcenter/searchhandlers/khc_htdig.pl.cmake \
	khelpcenter/searchhandlers/khc_htsearch.pl \
	khelpcenter/searchhandlers/khc_mansearch.pl \
	kioslave/info/kde-info2html

CONF_FILES+=	${PREFIX}/share/examples/kdebase-runtime4/kde-information.menu \
                ${PKG_SYSCONFDIR}/xdg/menus/kde-information.menu
CONF_FILES+=	${PREFIX}/share/examples/kde4-dbus/org.kde.kcontrol.kcmremotewidgets.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.kcontrol.kcmremotewidgets.conf

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.attica?=	attica>=0.1.4
.include "../../misc/attica/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
