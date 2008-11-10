# $NetBSD: Makefile,v 1.7 2008/11/10 17:21:39 wiz Exp $
#

DISTNAME=		xman-1.0.3
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Manual page browser

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	MANCONF=/etc/man.conf
.endif

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXprintUtil/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
