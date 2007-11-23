# $NetBSD: Makefile,v 1.2 2007/11/23 12:23:39 bjs Exp $

DISTNAME=	sessreg-1.0.3
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Manage utmp/wtmp entries for xdm

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

BUILD_DEFS+=	VARBASE
CONFIGURE_ARGS+=--localstatedir=${VARBASE:Q}

###
### Please see patches/patch-ab for details on this.
###
#.if ${OPSYS} == "SomePlatform"
#CPPFLAGS+=	-DNO_COLON_ZERO_IN_UTMP
#.endif


.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
