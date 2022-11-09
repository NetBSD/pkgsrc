# $NetBSD: Makefile,v 1.21 2022/11/09 13:14:20 joerg Exp $

DISTNAME=		libXau-1.0.10
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Authorization Protocol for X from X.org
LICENSE=		mit

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

PKGCONFIG_OVERRIDE+=	xau.pc.in

CPPFLAGS.OSF1+=		-pthread # Required by compiler if including pthread.h

X11_LIB_NAME?=		libXau
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
