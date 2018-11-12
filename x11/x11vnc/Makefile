# $NetBSD: Makefile,v 1.74 2018/11/12 03:53:14 ryoon Exp $
#

DISTNAME=	x11vnc-0.9.13
PKGREVISION=	36
CATEGORIES=	x11 net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libvncserver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.karlrunge.com/x11vnc/
COMMENT=	VNC server for real X displays
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-system-libvncserver

PTHREAD_AUTO_VARS=	yes
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread||g'

.include "options.mk"

BUILD_DIRS=	x11vnc
INSTALL_DIRS=	x11vnc classes

.include "../../security/openssl/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
