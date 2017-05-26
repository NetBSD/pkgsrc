# $NetBSD: Makefile,v 1.73 2017/05/26 09:28:14 wiz Exp $

DISTNAME=		libdrm-2.4.81
CATEGORIES=		x11 graphics
MASTER_SITES=		http://dri.freedesktop.org/libdrm/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://dri.freedesktop.org/wiki/DRM
COMMENT=		Userspace interface to kernel DRM services

ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-* FreeBSD-*-* OpenBSD-*-* \
			Linux-*-* SunOS-*-*

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libdrm.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		atomic
SUBST_FILES.atomic=	xf86drm.h
SUBST_MESSAGE.atomic=	Configuring xf86drm.h's atomic operations.
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

PLIST_VARS+=	intel arm
.if !empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Mx86_64)
# libpciaccess is needed to build support for the intel KMS API,
# libdrm_intel.so.
.include "../../sysutils/libpciaccess/buildlink3.mk"
PLIST.intel=	yes
.elif !empty(MACHINE_ARCH:Marm*) || \
      !empty(MACHINE_ARCH:Mearm*) || \
      !empty(MACHINE_ARCH:Maarch64)
PLIST.arm=	yes
#.else
#CONFIGURE_ARGS+=	--disable-intel
.endif
.include "../../mk/bsd.pkg.mk"
