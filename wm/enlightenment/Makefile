# $NetBSD: Makefile,v 1.36 2006/12/02 18:20:43 obache Exp $

DISTNAME=	e16-0.16.8.4
PKGNAME=	${DISTNAME:S/e16/enlightenment/}
CATEGORIES=	x11 gnome wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://enlightenment.org.au/
COMMENT=	Highly themeable and configurable window manager

USE_TOOLS+=		bison perl:run pkg-config
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-fsstd
CONFIGURE_ARGS+=	--enable-xrandr
CONFIGURE_ARGS+=	--disable-composite
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--disable-hints-gnome
CONFIGURE_ARGS+=	--disable-hints-kde
MAKE_ENV+=		USER=${SHAREOWN}:${SHAREGRP}

INSTALL_MAKE_FLAGS+=	sesmdir=${WRKDIR}/.tmp
INSTALLATION_DIRS=	etc/X11/dm/Sessions
CONF_FILES+=		${PREFIX}/share/e16/misc/e16.desktop \
			  ${PREFIX}/etc/X11/dm/Sessions/e16.desktop

REPLACE_PERL=		sample-scripts/bouncingball.pl
REPLACE_PERL+=		sample-scripts/testroller.pl
REPLACE_PERL+=		sample-scripts/shade-pagers.pl
REPLACE_PERL+=		scripts/e_gen_menu

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	scripts/e_gen_menu
SUBST_SED.paths=	-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@X11BASE@,${X11BASE},g'

post-install:
	${FIND} ${PREFIX}/share/e16/themes -type d -print | \
	${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${PREFIX}/share/e16/themes -type f -print | \
	${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../audio/esound/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
