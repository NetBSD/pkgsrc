# $NetBSD: Makefile,v 1.104 2026/02/06 10:06:20 wiz Exp $
#

DISTNAME=	x11vnc-0.9.17
PKGREVISION=	3
CATEGORIES=	x11 net
MASTER_SITES=	${MASTER_SITE_GITHUB:=LibVNC/}
GITHUB_PROJECT=	x11vnc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LibVNC/x11vnc
COMMENT=	VNC server for real X displays
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	autoconf automake autoreconf gmake pkg-config
GNU_CONFIGURE=	yes

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../security/openssl/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
