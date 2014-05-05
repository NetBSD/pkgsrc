# $NetBSD: Makefile,v 1.43 2014/05/05 00:48:31 ryoon Exp $

DISTNAME=	kde-runtime-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
PKGREVISION=	6
CATEGORIES=	x11
COMMENT=	Runtime requirements for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1
CMAKE_ARGS+=	-DWITH_LibSSH:BOOL=OFF
CMAKE_ARGS+=	-DLIBLZMA_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.xz}/include
CMAKE_ARGS+=	-DLIBLZMA_LIBRARY:FILEPATH=${BUILDLINK_PREFIX.xz}/lib/liblzma.so

DEPENDS+=	htdig>=3.2.0:../../www/htdig
DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons

USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

# Some files are conditional on 'md5sum' or 'md5' being present.
PLIST_VARS+=	md5
.for dir in ${PATH:C/\:/ /g}
.  if exists(${dir}/md5sum) || exists(${dir}/md5)
PLIST.md5=	yes
.  endif
.endfor

SUBST_CLASSES+=		htdig
SUBST_STAGE.htdig=	post-patch
SUBST_MESSAGE.htdig=	Fix htdig paths.
SUBST_FILES.htdig=	khelpcenter/searchhandlers/khc_htsearch.pl
SUBST_SED.htdig=	-e s:/srv/www/cgi-bin:${PREFIX}/libexec/cgi-bin:

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	kioslave/info/kde-info2html.conf
SUBST_SED.paths=	-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_STAGE.paths=	post-patch

REPLACE_PERL+= \
	khelpcenter/searchhandlers/khc_docbookdig.pl.cmake \
	khelpcenter/searchhandlers/khc_htdig.pl.cmake \
	khelpcenter/searchhandlers/khc_htsearch.pl \
	khelpcenter/searchhandlers/khc_mansearch.pl \
	kioslave/info/kde-info2html

CONF_FILES+=	${PREFIX}/share/examples/kde-runtime4/kde-information.menu \
                ${PKG_SYSCONFDIR}/xdg/menus/kde-information.menu
CONF_FILES+=	${PREFIX}/share/examples/kde4-dbus/org.kde.kcontrol.kcmremotewidgets.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.kcontrol.kcmremotewidgets.conf

BUILDLINK_DEPMETHOD.qt4-tools=	full

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
#.include "../../lang/python/application.mk"
# not the libssh the package wants
#.include "../../security/libssh/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../misc/nepomuk-core/buildlink3.mk"
.include "../../multimedia/phonon/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.attica?=	attica>=0.1.4
.include "../../misc/attica/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_ABI_DEPENDS.soprano?=	soprano>=2.6.50
.include "../../textproc/soprano/buildlink3.mk"
.include "../../x11/kactivities/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
