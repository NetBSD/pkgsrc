# $NetBSD: Makefile,v 1.34 2016/02/26 11:27:16 jperkin Exp $
#

DISTNAME=	mrxvt-0.5.4
PKGREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=materm/}
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	mrxvt-0.5.4-001-fix-segfault-when-wd-empty.patch

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/mrxvt/
COMMENT=	Multi-tabbed terminal emulator with Xft support

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_FEATURES+=		snprintf

CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--enable-text-shadow
CONFIGURE_ARGS+=	--enable-24bits
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CONFIGURE_ARGS.HPUX+=	--disable-lastlog --disable-utmp --disable-wtmp

EGDIR=			${PREFIX}/share/examples
MAKE_DIRS+=		${PKG_SYSCONFDIR}/mrxvt
CONF_FILES=		${EGDIR}/mrxvt/mrxvtrc ${PKG_SYSCONFDIR}/mrxvt/mrxvtrc
CONF_FILES+=		${EGDIR}/mrxvt/default.menu ${PKG_SYSCONFDIR}/mrxvt/default.menu
CONF_FILES+=		${EGDIR}/mrxvt/submenus.menu ${PKG_SYSCONFDIR}/mrxvt/submenus.menu

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly"
# Make mrxvt setuid root so that tty ownership setting and utmp logging
# function correctly.
#
CONFIGURE_ARGS+=	--enable-ttygid
SPECIAL_PERMS=		${PREFIX}/bin/mrxvt ${SETUID_ROOT_PERMS}
.endif

BUILDLINK_DEPMETHOD.libXt+=	build

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
