# $NetBSD: Makefile,v 1.14 2012/07/15 08:23:00 wiz Exp $
#

DISTNAME=		matchbox-desktop-0.9.1
PKGREVISION=		8
CATEGORIES=		x11
MASTER_SITES=		http://matchbox-project.org/sources/matchbox-desktop/0.9/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matchbox-project.org/
COMMENT=		Desktop manager for Matchbox

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=	matchbox-desktop.pc.in

CONFIGURE_ARGS+=	--enable-startup-notification

PKG_SYSCONFSUBDIR=	matchbox
EGDIR=			${PREFIX}/share/examples/matchbox-desktop
CONF_FILES=		${EGDIR}/mbdesktop_modules ${PKG_SYSCONFDIR}/mbdesktop_modules

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
