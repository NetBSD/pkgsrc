# $NetBSD: Makefile,v 1.73 2019/12/07 04:50:49 gutteridge Exp $

DISTNAME=	e16-1.0.21
PKGNAME=	${DISTNAME:S/e16/enlightenment/}
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://enlightenment.org/
COMMENT=	Highly themeable and configurable window manager
LICENSE=	enlightenment16

USE_TOOLS+=		perl:run pkg-config
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-hints-gnome
MAKE_ENV+=		USER=${SHAREOWN}:${SHAREGRP}

INSTALL_MAKE_FLAGS+=	sesmdir=${WRKDIR}/.tmp

REPLACE_PERL=		sample-scripts/bouncingball.pl
REPLACE_PERL+=		sample-scripts/testroller.pl
REPLACE_PERL+=		sample-scripts/shade-pagers.pl
REPLACE_PERL+=		scripts/e_gen_menu

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	scripts/e_gen_menu
SUBST_VARS.paths=	LOCALBASE
SUBST_VARS.paths+=	PREFIX
SUBST_VARS.paths+=	X11BASE

PLIST_VARS+=	libhack

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly" || ${OPSYS} == "SunOS" || ${OPSYS} == "Linux" || \
    ${OPSYS} == "Darwin"
PLIST.libhack=	yes
.endif

post-install:
	${FIND} ${DESTDIR}${PREFIX}/share/e16/themes -type d -print | \
		${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${DESTDIR}${PREFIX}/share/e16/themes -type f -print | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	cd ${DESTDIR}${PREFIX}/share/e16 && ${RM} -rf fonts

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
