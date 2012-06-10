# $NetBSD: Makefile,v 1.4 2012/06/10 16:40:24 wiz Exp $

DISTNAME=	sessreg-1.0.7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
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
