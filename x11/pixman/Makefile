# $NetBSD: Makefile,v 1.89 2023/09/29 09:27:07 adam Exp $

DISTNAME=	pixman-0.42.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Library of low-level pixel manipulation routines
LICENSE=	mit

CHECK_PORTABILITY_SKIP+=	Makefile.am # already patched in Makefile.in

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == i386
CONFIGURE_ARGS+=	--disable-sse2
.endif

.if ${PKGSRC_COMPILER:Mclang} && ${MACHINE_ARCH} == "aarch64"
# NEON macros depend on GNU as, but Xcode ships llvm-as
CONFIGURE_ARGS+=	--disable-arm-a64-neon
.endif

PKGCONFIG_OVERRIDE+=	pixman-1.pc.in
PKGCONFIG_OVERRIDE+=	pixman-1-uninstalled.pc.in

TEST_TARGET=	check

X11_LIB_NAME?=		pixman
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../mk/bsd.pkg.mk"
