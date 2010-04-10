# $NetBSD: Makefile,v 1.7 2010/04/10 02:45:04 markd Exp $

DISTNAME=	kdebase-runtime-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Runtime requirements for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=off

DEPENDS+=	htdig>=3.2.0:../../www/htdig-devel
DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons

.include "options.mk"

SUBST_CLASSES+=		htdig paths
SUBST_STAGE.htdig=	post-patch
SUBST_MESSAGE.htdig=	Fix htdig paths.
SUBST_FILES.htdig=	khelpcenter/searchhandlers/khc_htsearch.pl
SUBST_SED.htdig=	-e s:/srv/www/cgi-bin:${PREFIX}/libexec/cgi-bin:

SUBST_FILES.paths=	kioslave/info/kde-info2html.conf
SUBST_SED.paths=	-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_STAGE.paths=	post-patch

REPLACE_BASH+= pics/oxygen/scalable/export_pngs.sh

REPLACE_PERL+= \
	khelpcenter/searchhandlers/khc_docbookdig.pl.cmake \
	khelpcenter/searchhandlers/khc_htdig.pl.cmake \
	khelpcenter/searchhandlers/khc_htsearch.pl \
	khelpcenter/searchhandlers/khc_mansearch.pl \
	kioslave/info/kde-info2html

CONF_FILES+=	${PREFIX}/share/examples/kdebase-runtime4/kde-information.menu \
                ${PKG_SYSCONFDIR}/xdg/menus/kde-information.menu

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/attica/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
