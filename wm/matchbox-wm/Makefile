# $NetBSD: Makefile,v 1.15 2013/02/16 11:24:47 wiz Exp $
#

DISTNAME=		matchbox-window-manager-1.1
PKGNAME=		${DISTNAME:S/window-manager/wm/}
PKGREVISION=		4
CATEGORIES=		wm x11
MASTER_SITES=		http://projects.o-hand.com/matchbox/sources/matchbox-window-manager/1.1/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://projects.o-hand.com/matchbox/
COMMENT=		Window manager designed for computers with small displays

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

PKG_SYSCONFSUBDIR=	matchbox
EGDIR=			${PREFIX}/share/examples/matchbox
CONF_FILES=		${EGDIR}/kbdconfig ${PKG_SYSCONFDIR}/kbdconfig

INSTALLATION_DIRS+=	share/examples/matchbox

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/kbdconfig \
		${DESTDIR}${PREFIX}/share/examples/matchbox/

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
