# $NetBSD: Makefile,v 1.23 2013/11/08 13:11:44 wiz Exp $

DISTNAME=	libxcb-1.9.3
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	X protocol C-language Binding
LICENSE=	mit # with no-advertising clause

TOOL_DEPENDS+=	libxslt>=1.1.0:../../textproc/libxslt
TOOL_DEPENDS+=	${PYPKGPREFIX}-xcbgen>=1.9:../../x11/py-xcbgen

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--disable-build-docs	# or needs doxygen
CONFIGURE_ARGS+=	--without-doxygen

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
# No native C compiler needed -- the tool that gobbles up the xcb
# prototypes is in Python.
#
# XXX This needs to match the version of xcb-proto we get for the
# target by buildlink3.
TOOL_DEPENDS+=		xcb-proto-[0-9]*:../../x11/xcb-proto
.endif

# Adds -Wl,-R to pkgconfig files automatically
PKGCONFIG_OVERRIDE+=	xcb-composite.pc.in
PKGCONFIG_OVERRIDE+=	xcb-damage.pc.in
PKGCONFIG_OVERRIDE+=	xcb-dri3.pc.in
PKGCONFIG_OVERRIDE+=	xcb-dpms.pc.in
PKGCONFIG_OVERRIDE+=	xcb-glx.pc.in
PKGCONFIG_OVERRIDE+=	xcb-present.pc.in
PKGCONFIG_OVERRIDE+=	xcb-randr.pc.in
PKGCONFIG_OVERRIDE+=	xcb-record.pc.in
PKGCONFIG_OVERRIDE+=	xcb-render.pc.in
PKGCONFIG_OVERRIDE+=	xcb-res.pc.in
PKGCONFIG_OVERRIDE+=	xcb-screensaver.pc.in
PKGCONFIG_OVERRIDE+=	xcb-shape.pc.in
PKGCONFIG_OVERRIDE+=	xcb-shm.pc.in
PKGCONFIG_OVERRIDE+=	xcb-sync.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xevie.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xf86dri.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xfixes.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xinerama.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xprint.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xtest.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xv.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xvmc.pc.in
PKGCONFIG_OVERRIDE+=	xcb.pc.in

# libXdmcp is optional; adds support for XDM-AUTHORIZATION-1 in
# addition to MIT-MAGIC-COOKIE-1.

.include "../../mk/pthread.buildlink3.mk"

XTHREADLIB=	${${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}:L:M*}

.if empty(PTHREAD_CPPFLAGS)
XTHREAD_CPPFLAGS=	-D_REENTRANT
.else
XTHREAD_CPPFLAGS=	${PTHREAD_CPPFLAGS}
.endif

SUBST_CLASSES+=		pc
SUBST_FILES.pc=		xcb.pc.in
SUBST_MESSAGE.pc=	Configuring threading in xcb.pc.in.
SUBST_STAGE.pc=		pre-configure
SUBST_VARS.pc=		XTHREADLIB XTHREAD_CPPFLAGS

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

###
### XXX needed to build from scratch, but we're patching right now
###	so it's not needed (nor should it ever be, really).
###
#.include "../../devel/gperf/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=	tool
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.xcb-proto?=	xcb-proto>=1.9
.include "../../x11/xcb-proto/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
