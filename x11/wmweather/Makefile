# $NetBSD: Makefile,v 1.16 2004/03/26 02:28:02 wiz Exp $
#

DISTNAME=	wmweather-2.4.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.godisch.de/debian/wmweather/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.godisch.de/debian/wmweather/
COMMENT=	WindowMaker DockApp showing local weather conditions

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK2=		# defined
USE_X11=		yes

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

USE_PKGINSTALL=		yes
CONFIGURE_ARGS+=	--with-sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/wmweather.conf ${PKG_SYSCONFDIR}/wmweather.conf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket
.endif

.include "../../graphics/xpm/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
