# $NetBSD: Makefile,v 1.1 2015/07/02 12:38:32 rodent Exp $
#

DISTNAME=	proxymngr-1.0.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	X proxy manager service
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

EGDIR=		share/examples/proxymngr
CONF_FILES+=	${EGDIR}/pmconfig ${PKG_SYSCONFDIR}/X11/proxymngr/pmconfig

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/X11/proxymngr/pmconfig
	${INSTALL_DATA} ${WRKSRC}/pmconfig ${DESTDIR}${PREFIX}/${EGDIR}

BUILDLINK_API_DEPENDS.xproto+=	xproto>=7.0.17
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xproxymanagementprotocol/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
DEPENDS+=	lbxproxy-[0-9]*:../../x11/lbxproxy
.include "../../mk/bsd.pkg.mk"
