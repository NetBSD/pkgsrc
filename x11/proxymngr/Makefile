# $NetBSD: Makefile,v 1.5 2018/03/07 11:57:39 wiz Exp $

DISTNAME=	proxymngr-1.0.4
PKGREVISION=	1
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

EGDIR=		share/examples/proxymngr
CONF_FILES+=	${EGDIR}/pmconfig ${PKG_SYSCONFDIR}/X11/proxymngr/pmconfig

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/X11/proxymngr/pmconfig
	${INSTALL_DATA} ${WRKSRC}/pmconfig ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
