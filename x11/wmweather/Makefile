# $NetBSD: Makefile,v 1.14 2004/01/20 12:28:28 agc Exp $
#

DISTNAME=	wmweather-2.4.2
CATEGORIES=	x11
MASTER_SITES=	http://www.godisch.de/debian/wmweather/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.godisch.de/debian/wmweather/
COMMENT=	WindowMaker DockApp showing local weather conditions

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK2=		# defined
USE_X11=		yes

GNU_CONFIGURE=		yes
USE_GMAKE=		yes

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
