# $NetBSD: Makefile,v 1.95 2019/10/18 09:04:16 nia Exp $

DISTNAME=		libdrm-2.4.100
CATEGORIES=		x11 graphics
MASTER_SITES=		https://dri.freedesktop.org/libdrm/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://dri.freedesktop.org/wiki/DRM
COMMENT=		Userspace interface to kernel DRM services
LICENSE=		mit

# Platforms with kernel support for DRM
ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-* FreeBSD-*-* OpenBSD-*-* \
			Linux-*-* SunOS-*-*

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libdrm.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		atomic
SUBST_FILES.atomic=	xf86drm.h
SUBST_MESSAGE.atomic=	Configuring atomic operations in xf86drm.h
SUBST_STAGE.atomic=	pre-configure
SUBST_VARS.atomic=	ATOMIC_OPS_CHECK

ATOMIC_OPS_CHECK=	0
.if exists(${CROSS_DESTDIR}/usr/include/sys/atomic.h)
ATOMIC_OPS_CHECK=	1
.else
.  include "../../devel/libatomic_ops/buildlink3.mk"
CONFIGURE_ENV+=		drm_cv_atomic_primitives=libatomic-ops
.endif

CONFIGURE_ARGS+=	PTHREADSTUBS_CFLAGS=-I${PREFIX}/include \
			PTHREADSTUBS_LIBS=-L${PREFIX}/lib
CONFIGURE_ARGS+=	--disable-manpages
CONFIGURE_ARGS+=	--disable-valgrind

LDFLAGS.NetBSD+=	-lpci

PLIST_VARS+=	intel arm
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
# libpciaccess is needed to build support for the intel KMS API,
# libdrm_intel.so.
.include "../../sysutils/libpciaccess/buildlink3.mk"
PLIST.intel=	yes
.elif !empty(MACHINE_ARCH:Marm*) || \
      !empty(MACHINE_ARCH:Mearm*) || \
      ${MACHINE_ARCH} == "aarch64"
PLIST.arm=	yes
#.else
#CONFIGURE_ARGS+=	--disable-intel
.endif
.include "../../mk/bsd.pkg.mk"
