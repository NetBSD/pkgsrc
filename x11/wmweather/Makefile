# $NetBSD: Makefile,v 1.30 2006/12/27 13:37:43 joerg Exp $
#

DISTNAME=	wmweather-2.4.2
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://www.godisch.de/debian/wmweather/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.godisch.de/debian/wmweather/
COMMENT=	WindowMaker DockApp showing local weather conditions

WRKSRC=			${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake xmessage:run

CONFIGURE_ARGS+=	--with-sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-xmessage=${TOOLS_PATH.xmessage}

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/wmweather.conf ${PKG_SYSCONFDIR}/wmweather.conf

LDFLAGS.SunOS+=	-lsocket

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
