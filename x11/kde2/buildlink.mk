# $NetBSD: buildlink.mk,v 1.3 2001/12/07 07:21:30 jlam Exp $
#
# This Makefile fragment is included by packages that use the KDE2
# configure-and-build process.
#
# To use this Makefile fragment, simply include this Makefile fragment in
# the package Makefile.
#
# The buildlink strategy with KDE2 packages is:
#
#     * pass UIC to the configure script, as most of the KDE2 packages need
#	the path to the QT2 uic to build.
#
#     * pass USER_LDFLAGS to the configure script, containing the value of
#	LDFLAGS as set by bsd.pkg.mk; this should pass all of the necessary
#	library directory and rpath settings to the compiler/linker to find
#	the X11, Qt-2.x, and KDE-2.x libraries.
#
#     * pass KDEDIR and a hand-crafted ac_cv_have_kde to the configure
#	script, where KDEDIR contains the installed location of KDE,
#	and ac_cv_have_kde contains the buildlinked location of KDE; this
#	makes the KDE configure script install other KDE software in
#	${KDEDIR}, but build against the libraries in ${BUILDLINK_DIR}.
#
#     * override kde_libraries at build-time; the configure script will set
#	it to point into the buildlink directory and will add the correct
#	linker flags to find the KDE2 libraries in the buildlink directory,
#	but we need to point it to the actual install location of the KDE
#	libraries so that the build may find the libtool archives.
#
# We pass the following values via options to the configure script:
#
#     * datadir is where all of the KDE2 data files go
#     * qt-dir is the location of QT2 for build purposes
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

.if !defined(KDE2_BUILDLINK_MK)
KDE2_BUILDLINK_MK=	# defined

# All KDE2 packages satisfy the requirements for USE_X11BASE.  This also
# forces all KDE2 packages to have a common installation prefix.
#
USE_X11BASE=		YES

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_BUILDLINK_ONLY)
#
# Default values so that even if the package using this file is not strongly
# buildlinkified, there are sensible values for finding the KDE2 and Qt2
# headers and libraries.
#
KDEDIR?=		${X11PREFIX}
QTDIR?=			${X11PREFIX}/qt2
BUILDLINK_KDEDIR?=	${KDEDIR}
BUILDLINK_QTDIR?=	${QTDIR}
.endif

CONFIGURE_ARGS+=	--datadir="${KDEDIR}/share/kde"
CONFIGURE_ARGS+=	--with-qt-dir="${BUILDLINK_QTDIR}"
CONFIGURE_ARGS+=	--with-extra-includes="${_KDE2_EXTRA_INCLUDES}"
CONFIGURE_ARGS+=	--disable-rpath

CONFIGURE_ENV+=		UIC="${QTDIR}/bin/uic"
CONFIGURE_ENV+=		USER_LDFLAGS="${LDFLAGS}"
CONFIGURE_ENV+=		ac_cv_have_kde="${_KDE2_AC_CV_HAVE_KDE}"
LDFLAGS+=		-L${BUILDLINK_QTDIR}/lib

MAKE_FLAGS+=		kde_libraries="${KDEDIR}/lib"
MAKE_ENV+=		AM_MAKEFLAGS="${MAKE_FLAGS}"

_KDE2_EXTRA_INCLUDES?=	${BUILDLINK_DIR}/include:${BUILDLINK_X11_DIR}/include
_KDE2_AC_CV_HAVE_KDE?=	have_kde=yes					\
			ac_kde_includes=${BUILDLINK_KDEDIR}/include	\
			ac_kde_libraries=${BUILDLINK_KDEDIR}/lib

KDE_CONFIG_SITE?=	${KDEDIR}/share/kde/config.site			\
			${KDEDIR}/etc/config.site

CONFIGURE_ENV+=		KDEDIR="${KDEDIR}"
CONFIGURE_ENV+=		CONFIG_SITE="${KDE_CONFIG_SITE}"
CONFIGURE_ENV+=		kde_appsdir="${KDEDIR}/share/kde/applnk"
#CONFIGURE_ENV+=	kde_bindir="${KDEDIR}/bin"
CONFIGURE_ENV+=		kde_cgidir="${KDEDIR}/kde-cgi-bin"
CONFIGURE_ENV+=		kde_confdir="${KDEDIR}/share/kde/config"
CONFIGURE_ENV+=		kde_datadir="${KDEDIR}/share/kde/apps"
CONFIGURE_ENV+=		kde_htmldir="${KDEDIR}/share/doc/kde/HTML"
CONFIGURE_ENV+=		kde_icondir="${KDEDIR}/share/kde/icons"
CONFIGURE_ENV+=		kde_locale="${KDEDIR}/share/kde/locale"
CONFIGURE_ENV+=		kde_mimedir="${KDEDIR}/share/kde/mimelnk"
#CONFIGURE_ENV+=	kde_moduledir="${KDEDIR}/lib/kde2"
CONFIGURE_ENV+=		kde_servicesdir="${KDEDIR}/share/kde/services"
CONFIGURE_ENV+=		kde_servicetypesdir="${KDEDIR}/share/kde/servicetypes"
CONFIGURE_ENV+=		kde_sounddir="${KDEDIR}/share/kde/sounds"
CONFIGURE_ENV+=		kde_templatesdir="${KDEDIR}/share/kde/templates"
CONFIGURE_ENV+=		kde_toolbardir="${KDEDIR}/share/kde/toolbar"
CONFIGURE_ENV+=		kde_wallpaperdir="${KDEDIR}/share/kde/wallpapers"
.endif	# KDE2_BUILDLINK_MK
