# $NetBSD: Makefile,v 1.3 2006/02/05 23:11:14 joerg Exp $
#

DISTNAME=		matchbox-window-manager-0.9.5
PKGNAME=		${DISTNAME:S/window-manager/wm/}
PKGREVISION=		2
CATEGORIES=		wm x11
MASTER_SITES=		http://projects.o-hand.com/matchbox/sources/matchbox-window-manager/0.9/

MAINTAINER=		tech-pkg@NetBSD.org
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
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
