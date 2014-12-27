# $NetBSD: Makefile,v 1.12 2014/12/27 14:45:45 mef Exp $
#

DISTNAME=		numlockx-1.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://home.kde.org/~seli/numlockx/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE		http://home.kde.org/~seli/numlockx/
COMMENT=		Allows you to start X with numlock turned on

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
