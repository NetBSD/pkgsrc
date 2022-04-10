# $NetBSD: Makefile,v 1.79 2022/04/10 08:53:17 nia Exp $

DISTNAME=	pixman-0.40.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Library of low-level pixel manipulation routines
LICENSE=	mit

CHECK_PORTABILITY_SKIP+=	Makefile.am # already patched in Makefile.in

GNU_CONFIGURE=		yes
.if ${MACHINE_ARCH} == i386
CONFIGURE_ARGS+=	--disable-sse2
.endif

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl

PKGCONFIG_OVERRIDE+=	pixman-1.pc.in
PKGCONFIG_OVERRIDE+=	pixman-1-uninstalled.pc.in

X11_LIB_NAME?=		pixman
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../mk/bsd.pkg.mk"
