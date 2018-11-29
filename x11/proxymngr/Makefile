# $NetBSD: Makefile,v 1.6 2018/11/29 16:28:08 wiz Exp $

DISTNAME=	proxymngr-1.0.4
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	X proxy manager service
LICENSE=	x11

DEPENDS+=	lbxproxy-[0-9]*:../../x11/lbxproxy

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

OWN_DIRS+=	${PKG_SYSCONFDIR}/X11/proxymngr
EGDIR=		share/examples/proxymngr
CONF_FILES+=	${EGDIR}/pmconfig ${PKG_SYSCONFDIR}/X11/proxymngr/pmconfig

BUILD_DEFS+=	PKG_SYSCONFBASE

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/X11/proxymngr/pmconfig
	${INSTALL_DATA} ${WRKSRC}/pmconfig ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
