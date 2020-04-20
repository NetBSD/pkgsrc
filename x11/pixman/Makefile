# $NetBSD: Makefile,v 1.75 2020/04/20 06:40:05 wiz Exp $

DISTNAME=	pixman-0.40.0
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

.include "../../mk/bsd.pkg.mk"
