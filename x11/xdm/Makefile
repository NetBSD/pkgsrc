# $NetBSD: Makefile,v 1.6 2008/01/18 02:54:15 bjs Exp $

DISTNAME=	xdm-1.1.6
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	X Display Manager from modular X.org

DEPENDS+=	sessreg-[0-9]*:../../x11/sessreg

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-dynamic-greeter
CONFIGURE_ARGS+=	--enable-tcp-transport
CONFIGURE_ARGS+=	--enable-unix-transport

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

RCD_SCRIPTS=	xdm

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[3-4]*)
CFLAGS+=	-fno-strict-aliasing
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-random-device=/dev/urandom
.endif

.include "options.mk"

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
