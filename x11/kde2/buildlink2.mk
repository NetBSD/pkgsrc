# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:33 jlam Exp $
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
# We pass the following values via options to the configure script:
#
#     * datadir is where all of the KDE2 data files go
#     * qt-dir is the location of QT2 for build purposes
#     * extra-includes is where headers for dependencies may be found
#
# We _don't_ pass the following values via options to the configure script:
#
#     * extra-libs contains library directories that are added to both the
#	rpath via -R and to the linker flags via -L; we don't need this
#	since we pass them in directly via ${USER_LDFLAGS}
#
# We also disable the rpath setting by the configure script since it often
# guesses wrong on odd setups, and since we already pass all of the required
# flags through USER_LDFLAGS.

.if !defined(KDE2_BUILDLINK2_MK)
KDE2_BUILDLINK2_MK=	# defined

# All KDE2 packages satisfy the requirements for USE_X11BASE.  This also
# forces all KDE2 packages to have a common installation prefix.
#
USE_X11BASE=		YES

.include "../../mk/bsd.prefs.mk"

KDEDIR?=		${X11PREFIX}
QTDIR?=			${X11PREFIX}/qt2

CONFIGURE_ARGS+=	--datadir="${KDEDIR}/share/kde"
CONFIGURE_ARGS+=	--with-qt-dir="${QTDIR}"
CONFIGURE_ARGS+=	--with-extra-includes="${_KDE2_EXTRA_INCLUDES}"
CONFIGURE_ARGS+=	--disable-rpath
.if exists(${X11BASE}/lib/libXinerama.so)
CONFIGURE_ARGS+=	--with-xinerama
.endif

CONFIGURE_ENV+=		UIC="${QTDIR}/bin/uic"
CONFIGURE_ENV+=		USER_LDFLAGS="${LDFLAGS}"
LDFLAGS+=		-L${QTDIR}/lib

_KDE2_EXTRA_INCLUDES?=	${LOCALBASE}/include:${X11BASE}/include

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

.endif	# KDE2_BUILDLINK2_MK
