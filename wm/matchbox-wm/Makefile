# $NetBSD: Makefile,v 1.7 2006/12/15 20:33:02 joerg Exp $
#

DISTNAME=		matchbox-window-manager-1.1
PKGNAME=		${DISTNAME:S/window-manager/wm/}
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/matchbox
	${MV} ${PKG_SYSCONFDIR}/kbdconfig \
		${PREFIX}/share/examples/matchbox/

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
