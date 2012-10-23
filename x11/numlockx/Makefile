# $NetBSD: Makefile,v 1.10 2012/10/23 10:24:20 wiz Exp $
#

DISTNAME=		numlockx-1.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://ktown.kde.org/~seli/numlockx/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ktown.kde.org/~seli/numlockx/
COMMENT=		Allows you to start X with numlock turned on

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	share/doc/numlockx

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/numlockx

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11:Q}/lib${LIBABISUFFIX:Q}
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
