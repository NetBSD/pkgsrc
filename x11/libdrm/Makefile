# $NetBSD: Makefile,v 1.115 2024/06/08 11:54:40 wiz Exp $

DISTNAME=		libdrm-2.4.121
CATEGORIES=		x11 graphics
MASTER_SITES=		https://dri.freedesktop.org/libdrm/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://dri.freedesktop.org/wiki/DRM
COMMENT=		Userspace interface to kernel DRM services
LICENSE=		mit

TOOL_DEPENDS+=		${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

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
MESON_ARGS+=	-Dintel=enabled
MESON_ARGS+=	-Dvmwgfx=enabled
.include "../../sysutils/libpciaccess/buildlink3.mk"
PLIST.intel=	yes
.else
MESON_ARGS+=	-Dintel=disabled
MESON_ARGS+=	-Dvmwgfx=disabled
.endif

MESON_ARGS+=	-Dradeon=enabled
MESON_ARGS+=	-Damdgpu=enabled
MESON_ARGS+=	-Dnouveau=enabled

.if ${MACHINE_ARCH:Marm*} || \
      ${MACHINE_ARCH:Mearm*} || \
      ${MACHINE_ARCH} == "aarch64"
MESON_ARGS+=	-Detnaviv=enabled
MESON_ARGS+=	-Dexynos=enabled
MESON_ARGS+=	-Dfreedreno=enabled
MESON_ARGS+=	-Dvc4=enabled
MESON_ARGS+=	-Domap=enabled
MESON_ARGS+=	-Dtegra=enabled
PLIST.arm=	yes
.else
MESON_ARGS+=	-Detnaviv=disabled
MESON_ARGS+=	-Dexynos=disabled
MESON_ARGS+=	-Dfreedreno=disabled
MESON_ARGS+=	-Domap=disabled
MESON_ARGS+=	-Dtegra=disabled
MESON_ARGS+=	-Dvc4=disabled
.endif

MESON_ARGS+=	-Dman-pages=enabled
MESON_ARGS+=	-Dvalgrind=disabled

SUBST_CLASSES+=		doc
SUBST_MESSAGE.doc=	Fixing rst2man name due to python versioning.
SUBST_STAGE.doc=	pre-configure
SUBST_FILES.doc=	meson.build
SUBST_SED.doc=		-e 's,rst2man.py,rst2man-${PYVERSSUFFIX},g'

LDFLAGS.NetBSD+=	-lpci
CPPFLAGS.SunOS+=	-D__EXTENSIONS__	# posix_memalign, ...

X11_LIB_NAME?=		libdrm
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
