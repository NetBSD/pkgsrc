# $NetBSD: Makefile,v 1.15 2012/10/29 05:06:41 asau Exp $
#

# materm is now mrxvt
DISTNAME=	multi-aterm-0.0.4
PKGREVISION=	1
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-terminal for the X Window System based on aterm

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-mousewheel
CONFIGURE_ARGS+=	--enable-swapscreen
CONFIGURE_ARGS+=	--enable-keepscrolling
CONFIGURE_ARGS+=	--enable-half-shadow
CONFIGURE_ARGS+=	--enable-shading
CONFIGURE_ARGS+=	--enable-fading
CONFIGURE_ARGS+=	--enable-transparency
CONFIGURE_ARGS+=	--with-xpm=${BUILDLINK_PREFIX.libXpm}

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX:Q}/lib
.endif

.include "options.mk"

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
