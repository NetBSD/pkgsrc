# $NetBSD: Makefile,v 1.47 2017/01/01 16:06:40 adam Exp $

DISTNAME=	wmweather-2.4.5
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://people.debian.org/~godisch/wmweather/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://people.debian.org/~godisch/
COMMENT=	WindowMaker DockApp showing local weather conditions
LICENSE=	gnu-gpl-v2

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

.include "../../mk/bsd.pkg.mk"
