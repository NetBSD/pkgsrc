# $NetBSD: Makefile,v 1.8 2008/07/14 12:56:19 joerg Exp $
#

DISTNAME=		matchbox-desktop-0.9.1
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		http://projects.o-hand.com/matchbox/sources/matchbox-desktop/0.9/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://project.o-hand.com/matchbox/
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
.include "../../mk/bsd.pkg.mk"
