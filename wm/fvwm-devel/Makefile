# $NetBSD: Makefile,v 1.5 2004/10/03 00:18:22 tv Exp $

DISTNAME=	fvwm-2.5.10
PKGNAME=	${DISTNAME:S/fvwm/&-devel/}
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://www.fvwm.org/
COMMENT=	Development version of X11 Virtual window manager

CONFLICTS=	fvwm-[0-9]* fvwm1-[0-9]* fvwm2-[0-9]*

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES

CONFIGURE_ARGS+=	--disable-bidi
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--without-rplay-library
CONFIGURE_ARGS+=	--without-stroke-library

post-install:
	${INSTALL_MAN} ${WRKSRC}/modules/FvwmGtk/FvwmGtk.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fvwm
	cd ${WRKSRC}/sample.fvwmrc && ${INSTALL_DATA} \
		`${LS} | ${GREP} -v Makefile` \
		${PREFIX}/share/examples/fvwm

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
