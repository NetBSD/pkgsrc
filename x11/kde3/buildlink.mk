# $NetBSD: buildlink.mk,v 1.1.1.1 2002/05/31 13:15:51 skrll Exp $
#
# This Makefile fragment is included by packages that use the KDE3
# configure-and-build process.
#
# To use this Makefile fragment, simply include this Makefile fragment in
# the package Makefile.
#
# The buildlink strategy with KDE3 packages is:
#
#     * pass UIC to the configure script, as the KDE3 configure scripts now
#	check for its existance and fail if its not found.
#
#     * pass USER_LDFLAGS to the configure script, containing the value of
#	LDFLAGS as set by bsd.pkg.mk; this should pass all of the necessary
#	library directory and rpath settings to the compiler/linker to find
#	the X11, Qt-3.x, and KDE-3.x libraries.
#
#     * pass KDEDIR and a hand-crafted ac_cv_have_kde to the configure
#	script, where KDEDIR contains the installed location of KDE,
#	and ac_cv_have_kde contains the buildlinked location of KDE; this
#	makes the KDE configure script install other KDE software in
#	${KDEDIR}, but build against the libraries in ${BUILDLINK_DIR}.
#
#     * override kde_libraries at build-time; the configure script will set
#	it to point into the buildlink directory and will add the correct
#	linker flags to find the KDE3 libraries in the buildlink directory,
#	but we need to point it to the actual install location of the KDE
#	libraries so that the build may find the libtool archives.
#
# We pass the following values via options to the configure script:
#
#     * datadir is where all of the KDE3 data files go
#     * qt-dir is the location of QT3 for build purposes
#     * extra-includes is where headers for dependencies may be found;
#	since we're using the buildlink infrastructure, this should contain
#	${BUILDLINK_DIR} and ${BUILDLINK_X11_DIR}.
#
# We _don't_ pass the following values via options to the configure script:
#
#     * extra-libs contains library directories that are added to both the
#	rpath via -R and to the linker flags via -L; we don't need this
#	since we need different directories for -R/-L and we can pass them
#	in directly via ${USER_LDFLAGS}
#
# We also disable the rpath setting by the configure script since it often
# guesses wrong on odd setups, and since we already pass all of the required
# flags through USER_LDFLAGS.
#
# The qt3-tools and qt3-libs buildlink files are also pulled in as all KDE
# pkgs need them.

.if !defined(KDE3_BUILDLINK_MK)
KDE3_BUILDLINK_MK=	# defined

# All KDE3 packages satisfy the requirements for USE_X11BASE.  This also
# forces all KDE3 packages to have a common installation prefix.
#
USE_X11BASE=		YES

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_BUILDLINK_ONLY)
#
# Default values so that even if the package using this file is not strongly
# buildlinkified, there are sensible values for finding the KDE3 and Qt3
# headers and libraries.
#
KDEDIR?=		${X11PREFIX}
QTDIR?=			${X11PREFIX}/qt3
BUILDLINK_KDEDIR?=	${KDEDIR}
BUILDLINK_QTDIR?=	${QTDIR}
.endif

CONFIGURE_ARGS+=	--datadir="${KDEDIR}/share/kde"
CONFIGURE_ARGS+=	--with-qt-dir="${BUILDLINK_QTDIR}"
CONFIGURE_ARGS+=	--with-extra-includes="${_KDE3_EXTRA_INCLUDES}"
CONFIGURE_ARGS+=	--disable-rpath
.if exists(${X11BASE}/lib/libXinerama.so)
CONFIGURE_ARGS+=	--with-xinerama
.endif

#
# These help when using auto*
#CONFIGURE_ENV+=		AUTOMAKE="${LOCALBASE}/bin/automake"
#CONFIGURE_ENV+=		AUTOCONF="${LOCALBASE}/bin/autoconf"
#AUTOMAKE_OVERRIDE=	NO

CONFIGURE_ENV+=		USER_LDFLAGS="${LDFLAGS}"
CONFIGURE_ENV+=		ac_cv_have_kde="${_KDE3_AC_CV_HAVE_KDE}"
LDFLAGS+=		-L${BUILDLINK_QTDIR}/lib

MAKE_FLAGS+=		kde_libraries="${KDEDIR}/lib"
MAKE_ENV+=		AM_MAKEFLAGS="${MAKE_FLAGS}"

_KDE3_EXTRA_INCLUDES?=	${BUILDLINK_DIR}/include:${BUILDLINK_X11_DIR}/include
_KDE3_AC_CV_HAVE_KDE?=	have_kde=yes					\
			ac_kde_includes=${BUILDLINK_KDEDIR}/include	\
			ac_kde_libraries=${BUILDLINK_KDEDIR}/lib

KDE_CONFIG_SITE?=	${KDEDIR}/share/kde/config.site			\
			${KDEDIR}/etc/config.site

CONFIGURE_ENV+=		KDEDIR="${KDEDIR}"
CONFIGURE_ENV+=		CONFIG_SITE="${KDE_CONFIG_SITE}"
CONFIGURE_ENV+=		kde_appsdir="${KDEDIR}/share/kde/applnk"
CONFIGURE_ENV+=		kde_cgidir="${KDEDIR}/kde-cgi-bin"
CONFIGURE_ENV+=		kde_confdir="${KDEDIR}/share/kde/config"
CONFIGURE_ENV+=		kde_datadir="${KDEDIR}/share/kde/apps"
CONFIGURE_ENV+=		kde_htmldir="${KDEDIR}/share/doc/kde/HTML"
CONFIGURE_ENV+=		kde_icondir="${KDEDIR}/share/kde/icons"
CONFIGURE_ENV+=		kde_locale="${KDEDIR}/share/kde/locale"
CONFIGURE_ENV+=		kde_mimedir="${KDEDIR}/share/kde/mimelnk"
CONFIGURE_ENV+=		kde_servicesdir="${KDEDIR}/share/kde/services"
CONFIGURE_ENV+=		kde_servicetypesdir="${KDEDIR}/share/kde/servicetypes"
CONFIGURE_ENV+=		kde_sounddir="${KDEDIR}/share/kde/sounds"
CONFIGURE_ENV+=		kde_templatesdir="${KDEDIR}/share/kde/templates"
CONFIGURE_ENV+=		kde_toolbardir="${KDEDIR}/share/kde/toolbar"
CONFIGURE_ENV+=		kde_wallpaperdir="${KDEDIR}/share/kde/wallpapers"

BUILDLINK_DEPENDS_METHOD.qt3-tools=	build

.include "../../x11/qt3-tools/buildlink.mk"

.endif	# KDE3_BUILDLINK_MK
