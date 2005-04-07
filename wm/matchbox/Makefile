# $NetBSD: Makefile,v 1.16 2005/04/07 13:40:49 ben Exp $
#

DISTNAME=		matchbox-window-manager-0.9.3
PKGNAME=		matchbox-0.9.3
CATEGORIES=		wm x11
MASTER_SITES=		http://matchbox.handhelds.org/sources/matchbox-window-manager/0..9/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://matchbox.handhelds.org/
COMMENT=		Window manager designed for computers with small displays

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

PKG_SYSCONFSUBDIR=	matchbox
EGDIR=			${PREFIX}/share/examples/matchbox
CONF_FILES=		${EGDIR}/kbdconfig ${PKG_SYSCONFDIR}/kbdconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/matchbox
	${MV} ${PKG_SYSCONFDIR}/kbdconfig \
		${PREFIX}/share/examples/matchbox/

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
