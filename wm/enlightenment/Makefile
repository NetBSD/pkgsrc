# $NetBSD: Makefile,v 1.35 2006/07/10 08:50:23 rillig Exp $

DISTNAME=	enlightenment-0.16.7.2
PKGREVISION=	3
CATEGORIES=	x11 gnome wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://enlightenment.org.au/
COMMENT=	Highly themeable and configurable window manager

USE_TOOLS+=		bison perl:run
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-fsstd
CONFIGURE_ARGS+=	--enable-xrandr
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--disable-hints-gnome
CONFIGURE_ARGS+=	--disable-hints-kde
CONFIGURE_ARGS+=	--with-imlib-prefix=${BUILDLINK_PREFIX.imlib2}
MAKE_ENV+=		USER=${SHAREOWN}:${SHAREGRP}

INSTALL_MAKE_FLAGS+=	sesmdir=${WRKDIR}/.tmp
INSTALLATION_DIRS=	etc/X11/dm/Sessions
CONF_FILES+=		${PREFIX}/share/enlightenment/misc/enlightenment.desktop \
			  ${PREFIX}/etc/X11/dm/Sessions/enlightenment.desktop

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
	${FIND} ${PREFIX}/share/enlightenment/themes -type d -print | \
	${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${PREFIX}/share/enlightenment/themes -type f -print | \
	${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/Xrandr/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
