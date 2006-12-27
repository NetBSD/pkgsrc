# $NetBSD: Makefile,v 1.20 2006/12/27 13:37:41 joerg Exp $

DISTNAME=	fvwm-${FVWM_VER}
#PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://www.fvwm.org/
COMMENT=	Development version of X11 Virtual window manager

CONFLICTS=	fvwm1-[0-9]* fvwm2-[0-9]*
FVWM_VER=	2.5.19

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES
USE_TOOLS+=		perl:run

PLIST_SUBST+=		FVWM_VER=${FVWM_VER:Q}

INSTALLATION_DIRS+=	share/examples/fvwm

CONFIGURE_ARGS+=	--disable-bidi
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--without-rplay-library
CONFIGURE_ARGS+=	--without-stroke-library

post-install:
	cd ${WRKSRC}/sample.fvwmrc && ${INSTALL_DATA} \
		`${LS} | ${GREP} -v Makefile` \
		${PREFIX}/share/examples/fvwm

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
