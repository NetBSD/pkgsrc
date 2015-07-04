# $NetBSD: Makefile,v 1.13 2015/07/04 18:06:37 richard Exp $

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

PKG_SYSCONFSUBDIR=	X11/lbxproxy
EGDIR=		${PREFIX}/share/examples/lbxproxy
CONF_FILES+=	${EGDIR}/AtomControl ${PKG_SYSCONFDIR}/AtomControl

INSTALLATION_DIRS+=	share/examples/lbxproxy

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/AtomControl ${DESTDIR}${EGDIR}/

.include "../../x11/bigreqsproto/buildlink3.mk"
.include "../../x11/xproxymanagementprotocol/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/liblbxutil/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
