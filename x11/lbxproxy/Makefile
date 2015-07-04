# $NetBSD: Makefile,v 1.12 2015/07/04 14:36:52 rodent Exp $

DISTNAME=	lbxproxy-1.0.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Proxy for Low Bandwidth extension (LBX) connections to X
LICENSE=	x11 # XXX and others

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

EGDIR=		share/examples/lbxproxy
CONF_FILES+=	${EGDIR}/AtomControl ${PKG_SYSCONFDIR}/X11/lbxproxy/AtomControl

INSTALLATION_DIRS+=	${EGDIR}

post-install:
		${RM} ${DESTDIR}${PKG_SYSCONFDIR}/X11/lbxproxy/AtomControl
		${INSTALL_DATA} ${WRKSRC}/config/AtomControl \
			${DESTDIR}${PREFIX}/${EGDIR}

.include "../../x11/bigreqsproto/buildlink3.mk"
.include "../../x11/xproxymanagementprotocol/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/liblbxutil/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
