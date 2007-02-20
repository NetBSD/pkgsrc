# $NetBSD: Makefile,v 1.8 2007/02/20 01:04:27 joerg Exp $
#

DISTNAME=		numlockx-1.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://ktown.kde.org/~seli/numlockx/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ktown.kde.org/~seli/numlockx/
COMMENT=		Allows you to start X with numlock turned on

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/numlockx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/numlockx

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11:Q}/lib${LIBABISUFFIX:Q}
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
