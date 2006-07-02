# $NetBSD: Makefile,v 1.11 2006/07/02 09:32:55 martti Exp $

DISTNAME=	fvwm-2.5.16
#PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://www.fvwm.org/
COMMENT=	Development version of X11 Virtual window manager

CONFLICTS=	fvwm1-[0-9]* fvwm2-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES

CONFIGURE_ARGS+=	--disable-bidi
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--without-rplay-library
CONFIGURE_ARGS+=	--without-stroke-library

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fvwm
	cd ${WRKSRC}/sample.fvwmrc && ${INSTALL_DATA} \
		`${LS} | ${GREP} -v Makefile` \
		${PREFIX}/share/examples/fvwm

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
