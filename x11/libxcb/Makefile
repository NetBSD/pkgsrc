# $NetBSD: Makefile,v 1.20 2013/02/01 14:40:29 jperkin Exp $
#

DISTNAME=	libxcb-1.9
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	X protocol C-language Binding
LICENSE=	mit # with no-advertising clause

BUILD_DEPENDS+=	libxslt>=1.1.0:../../textproc/libxslt
BUILD_DEPENDS+= ${PYPKGPREFIX}-xcbgen>=1.7:../../x11/py-xcbgen

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--disable-build-docs	# or needs doxygen
CONFIGURE_ARGS+=	--disable-doxygen

# Adds -Wl,-R to pkgconfig files automatically
PKGCONFIG_OVERRIDE+=	xcb-composite.pc.in
PKGCONFIG_OVERRIDE+=	xcb-damage.pc.in
PKGCONFIG_OVERRIDE+=	xcb-dpms.pc.in
PKGCONFIG_OVERRIDE+=	xcb-glx.pc.in
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
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.xcb-proto?=	xcb-proto>=1.8
.include "../../x11/xcb-proto/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
