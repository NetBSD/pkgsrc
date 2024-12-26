# $NetBSD: Makefile,v 1.95 2024/12/26 19:18:55 adam Exp $

DISTNAME=	pixman-0.44.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Library of low-level pixel manipulation routines
LICENSE=	mit

# gcc: fatal error: cannot read spec file 'libgomp.spec': No such file or directory
MESON_ARGS+=	-Dopenmp=disabled

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == i386
MESON_ARGS+=	-Dsse2=disabled
.endif

.if ${PKGSRC_COMPILER:Mclang} && ${MACHINE_ARCH} == "aarch64"
# NEON macros depend on GNU as, but Xcode ships llvm-as
MESON_ARGS+=	-Da64-neon=disabled
.endif

PKGCONFIG_OVERRIDE+=	output/meson-private/pixman-1.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

X11_LIB_NAME?=		pixman
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
