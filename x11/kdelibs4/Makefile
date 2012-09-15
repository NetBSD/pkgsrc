# $NetBSD: Makefile,v 1.46 2012/09/15 10:07:08 obache Exp $

DISTNAME=	kdelibs-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
PKGREVISION=	3
CATEGORIES=	x11
COMMENT=	Support libraries for the KDE integrated X11 desktop

#PATCH_SITES=	ftp://ftp.kde.org/pub/kde/security_patches/ \
#		http://mirrors.isc.org/pub/kde/security_patches/
#PATCHFILES=	post-kde-4.0.3-khtml.diff

.include "../../meta-pkgs/kde4/Makefile.kde4"

CONFLICTS=	kdelibs-[0-9]*

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_DEPENDENCIES_REWRITE= _KDE_build/KDELibsDependencies.cmake
CMAKE_DEPENDENCIES_REWRITE+= _KDE_build/KDELibsDependenciesInternal.cmake
CMAKE_MODULE_PATH_OVERRIDE+= kjsembed/qtonly/CMakeLists.txt

CMAKE_ARGS+=	-DKDE_DISTRIBUTION_TEXT:STRING="NetBSD pkgsrc"
CMAKE_ARGS+=	-DWITH_Avahi:BOOL=off

CMAKE_ARGS+=	-DLIBLZMA_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.xz}/include
CMAKE_ARGS+=	-DLIBLZMA_LIBRARY:FILEPATH=${BUILDLINK_PREFIX.xz}/lib/liblzma.so

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/kdelibs4/applications.menu \
		${PKG_SYSCONFDIR}/xdg/menus/applications.menu
CONF_FILES+=	${PREFIX}/share/examples/kde4-dbus/org.kde.auth.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.auth.conf

DEPENDS+=	docbook-xml>=4.2:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl>=1.75:../../textproc/docbook-xsl

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man7 ${PKGMANDIR}/man8

REPLACE_PERL+= \
	kio/proxytype.pl \
	kio/useragent.pl \
	kio/misc/fileshareset \
	kdeui/preparetips \
	plasma/data/kconfig_updates/plasma_popupapplet_fix_groups.pl

CHECK_PORTABILITY_SKIP+=kate/tests/hl/highlight.sh

SUBST_CLASSES+=			kdelibsfix
SUBST_STAGE.kdelibsfix=		pre-configure
SUBST_MESSAGE.kdelibsfix=	Fixing hardcoded paths.
SUBST_FILES.kdelibsfix= \
	kde3support/kdeui/k3sconfig.cpp \
	kio/kssl/kopenssl.cpp
SUBST_SED.kdelibsfix=		-e 's:@LOCALBASE@:${LOCALBASE}:g'

# XXX this is an ugly hack to avoid the WRKDIR path in the installed cmake file
SUBST_CLASSES+=			phononrelpath
SUBST_STAGE.phononrelpath=	post-configure
SUBST_MESSAGE.phononrelpath=	Fixing phonon RELWITHDEBINFO path
SUBST_FILES.phononrelpath=	_KDE_build/CMakeFiles/Export/${LOCALBASE:S^/^_^}/share/kde/apps/cmake/modules/KDELibs4LibraryTargets-relwithdebinfo.cmake
SUBST_SED.phononrelpath=	-e 's:[^"]*/\.buildlink/lib/libphonon\.so::'

USE_TOOLS+=	flex gmake
PLIST_VARS+=	kgrantpty

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# make sure zone.tab is installed
DEPENDS+=		zonetab-[0-9]*:../../time/zonetab
.endif

.if ${OPSYS} == "SunOS"
PLIST.kgrantpty=	yes
.endif

LDFLAGS.SunOS+=		-lintl

BUILDLINK_DEPMETHOD.qt4-tools=		full
.include "../../meta-pkgs/kde4/kde4.mk"

BUILDLINK_API_DEPENDS.strigi+=	strigi>=0.5.11
BUILDLINK_API_DEPENDS.soprano+=	soprano>=2.5.60
BUILDLINK_API_DEPENDS.shared-desktop-ontologies+=	shared-desktop-ontologies>=0.6.5

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../sysutils/strigi/buildlink3.mk"
.include "../../textproc/soprano/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/libdbusmenu-qt/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../misc/attica/buildlink3.mk"
.include "../../multimedia/phonon/buildlink3.mk"

# Avahi ? rather than mDNSResponder
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/polkit-qt/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/shared-desktop-ontologies/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
