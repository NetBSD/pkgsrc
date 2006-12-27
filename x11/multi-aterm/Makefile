# $NetBSD: Makefile,v 1.11 2006/12/27 13:37:43 joerg Exp $
#

DISTNAME=	multi-aterm-0.0.4
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.materm.tuxfamily.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.materm.tuxfamily.org/
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

.include "options.mk"

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
