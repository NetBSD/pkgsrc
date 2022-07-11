# $NetBSD: Makefile,v 1.103 2022/07/11 20:56:27 wiz Exp $

DISTNAME=		libdrm-2.4.112
CATEGORIES=		x11 graphics
MASTER_SITES=		https://dri.freedesktop.org/libdrm/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://dri.freedesktop.org/wiki/DRM
COMMENT=		Userspace interface to kernel DRM services
LICENSE=		mit

# Platforms with kernel support for DRM
ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-* FreeBSD-*-* OpenBSD-*-* \
			Linux-*-* SunOS-*-*

USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	amdgpu/libdrm_amdgpu.pc.in
PKGCONFIG_OVERRIDE+=	etnaviv/libdrm_etnaviv.pc.in
PKGCONFIG_OVERRIDE+=	exynos/libdrm_exynos.pc.in
PKGCONFIG_OVERRIDE+=	freedreno/libdrm_freedreno.pc.in
PKGCONFIG_OVERRIDE+=	intel/libdrm_intel.pc.in
PKGCONFIG_OVERRIDE+=	nouveau/libdrm_nouveau.pc.in
PKGCONFIG_OVERRIDE+=	omap/libdrm_omap.pc.in
PKGCONFIG_OVERRIDE+=	radeon/libdrm_radeon.pc.in
PKGCONFIG_OVERRIDE+=	tegra/libdrm_tegra.pc.in
PKGCONFIG_OVERRIDE+=	libdrm.pc.in

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		atomic
SUBST_FILES.atomic=	xf86drm.h
SUBST_MESSAGE.atomic=	Configuring atomic operations in xf86drm.h
SUBST_STAGE.atomic=	pre-configure
SUBST_VARS.atomic=	ATOMIC_OPS_CHECK

ATOMIC_OPS_CHECK=	0
.if exists(${_CROSS_DESTDIR}/usr/include/sys/atomic.h)
ATOMIC_OPS_CHECK=	1
.else
.  include "../../devel/libatomic_ops/buildlink3.mk"
.endif

PLIST_VARS+=	intel arm
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
MESON_ARGS+=	-Dintel=true
MESON_ARGS+=	-Dvmwgfx=true
.include "../../sysutils/libpciaccess/buildlink3.mk"
PLIST.intel=	yes
.else
MESON_ARGS+=	-Dintel=false
MESON_ARGS+=	-Dvmwgfx=false
.endif

MESON_ARGS+=	-Dradeon=true
MESON_ARGS+=	-Damdgpu=true
MESON_ARGS+=	-Dnouveau=true

.if ${MACHINE_ARCH:Marm*} || \
      ${MACHINE_ARCH:Mearm*} || \
      ${MACHINE_ARCH} == "aarch64"
MESON_ARGS+=	-Detnaviv=true
MESON_ARGS+=	-Dexynos=true
MESON_ARGS+=	-Dfreedreno=true
MESON_ARGS+=	-Dvc4=true
MESON_ARGS+=	-Domap=true
MESON_ARGS+=	-Dtegra=true
PLIST.arm=	yes
.else
MESON_ARGS+=	-Detnaviv=false
MESON_ARGS+=	-Dexynos=false
MESON_ARGS+=	-Dfreedreno=false
MESON_ARGS+=	-Domap=false
MESON_ARGS+=	-Dtegra=false
MESON_ARGS+=	-Dvc4=false
.endif

MESON_ARGS+=	-Dman-pages=false
MESON_ARGS+=	-Dvalgrind=false

LDFLAGS.NetBSD+=	-lpci
CPPFLAGS.SunOS+=	-D__EXTENSIONS__	# posix_memalign, ...

X11_LIB_NAME?=		libdrm
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
