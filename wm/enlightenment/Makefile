# $NetBSD: Makefile,v 1.23 2004/10/03 00:18:22 tv Exp $
#

DISTNAME=		enlightenment-0.16.7.1
PKGREVISION=	1
CATEGORIES=		x11 gnome wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Highly themeable and configurable window manager

USE_BUILDLINK3=		YES
USE_X11=		YES
USE_PERL5=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		yacc

CONFIGURE_ARGS+=	--enable-fsstd
CONFIGURE_ARGS+=	--enable-xrandr
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--disable-hints-gnome
CONFIGURE_ARGS+=	--disable-hints-kde
CONFIGURE_ARGS+=	--with-imlib-prefix=${BUILDLINK_PREFIX.imlib2}
MAKE_ENV+=		USER=${SHAREOWN}:${SHAREGRP}

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
	for FILE in `${GREP} "\.directory$$" ${PKGDIR}/PLIST`; do \
		${TOUCH} ${PREFIX}/$${FILE}; \
	done
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
