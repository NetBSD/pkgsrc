# $NetBSD: Makefile,v 1.30 2009/06/09 10:54:47 martti Exp $

DISTNAME=	fvwm-${FVWM_VER}
#PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fvwm.org/
COMMENT=	Development version of X11 Virtual window manager
LICENSE=	gnu-gpl-v2

CONFLICTS=	fvwm1-[0-9]* fvwm2-[0-9]*
FVWM_VER=	2.5.27

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

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

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-build
SUBST_MESSAGE.perl=	Fixing path to perl
SUBST_FILES.perl+=	bin/fvwm-convert-2.4
SUBST_FILES.perl+=	bin/fvwm-convert-2.6
SUBST_FILES.perl+=	bin/fvwm-menu-desktop
SUBST_FILES.perl+=	bin/fvwm-menu-directory
SUBST_FILES.perl+=	bin/fvwm-menu-headlines
SUBST_FILES.perl+=	bin/fvwm-menu-xlock
SUBST_FILES.perl+=	bin/fvwm-perllib
SUBST_FILES.perl+=	modules/FvwmConsole/FvwmConsoleC.pl
SUBST_FILES.perl+=	modules/FvwmDebug/FvwmDebug
SUBST_FILES.perl+=	modules/FvwmDebug/FvwmGtkDebug
SUBST_FILES.perl+=	modules/FvwmPerl/FvwmPerl
SUBST_FILES.perl+=	modules/FvwmTabs/FvwmTabs
SUBST_FILES.perl+=	modules/FvwmWindowMenu/FvwmWindowMenu
SUBST_FILES.perl+=	modules/FvwmScript/Scripts/FvwmScript-ComExample
SUBST_FILES.perl+=	modules/FvwmScript/Scripts/FvwmScript-Setup95
SUBST_SED.perl=		-e "s|${TOOLS_CMD.perl}|${PERL5}|"

post-install:
	cd ${WRKSRC}/sample.fvwmrc && ${INSTALL_DATA} \
		`ls | grep -v Makefile` ${DESTDIR}${PREFIX}/share/examples/fvwm

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
