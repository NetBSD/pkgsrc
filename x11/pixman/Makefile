# $NetBSD: Makefile,v 1.67 2018/08/22 09:48:03 wiz Exp $

DISTNAME=	pixman-0.34.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Library of low-level pixel manipulation routines
LICENSE=	mit

GNU_CONFIGURE=	yes
.if ${MACHINE_ARCH} == i386
CONFIGURE_ARGS+= --disable-sse2
.endif

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl

PKGCONFIG_OVERRIDE+=	pixman-1.pc.in
PKGCONFIG_OVERRIDE+=	pixman-1-uninstalled.pc.in

SUBST_CLASSES=		subdirs
SUBST_STAGE.subdirs=	pre-configure
SUBST_FILES.subdirs=	Makefile.in
SUBST_SED.subdirs=	-e "s|pixman demos test|pixman|"
SUBST_MESSAGE.lbase=	Skip building demos and test SUBDIRS

.include "../../mk/bsd.pkg.mk"
