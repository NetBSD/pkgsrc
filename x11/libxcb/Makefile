# $NetBSD: Makefile,v 1.39 2022/06/17 16:43:34 wiz Exp $

DISTNAME=	libxcb-1.15
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://xorg.freedesktop.org/archive/individual/lib/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	X protocol C-language Binding
LICENSE=	mit # with no-advertising clause

TOOL_DEPENDS+=	libxslt>=1.1.0:../../textproc/libxslt
TOOL_DEPENDS+=	${PYPKGPREFIX}-xcbgen>=1.15.1:../../x11/py-xcbgen

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--disable-devel-docs	# or needs doxygen
CONFIGURE_ARGS+=	--enable-xinput
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
PKGCONFIG_OVERRIDE+=	xcb-xinput.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xkb.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xprint.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xtest.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xv.pc.in
PKGCONFIG_OVERRIDE+=	xcb-xvmc.pc.in
PKGCONFIG_OVERRIDE+=	xcb.pc.in

# libXdmcp is optional; adds support for XDM-AUTHORIZATION-1 in
# addition to MIT-MAGIC-COOKIE-1.

.include "../../mk/pthread.buildlink3.mk"
LDFLAGS.OpenBSD+=	${PTHREAD_LDFLAGS}

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
X11_LIB_NAME?=		libxcb
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
PYTHON_FOR_BUILD_ONLY=	tool
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.xcb-proto?=	xcb-proto>=1.14
.include "../../x11/xcb-proto/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
