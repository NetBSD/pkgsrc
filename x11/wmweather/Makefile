# $NetBSD: Makefile,v 1.20 2005/04/11 21:48:14 tv Exp $
#

DISTNAME=	wmweather-2.4.2
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.godisch.de/debian/wmweather/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.godisch.de/debian/wmweather/
COMMENT=	WindowMaker DockApp showing local weather conditions

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_X11=		yes

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

USE_PKGINSTALL=		yes
CONFIGURE_ARGS+=	--with-sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/wmweather.conf ${PKG_SYSCONFDIR}/wmweather.conf

LDFLAGS.SunOS+=	-lsocket

.include "../../graphics/xpm/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
