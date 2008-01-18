# $NetBSD: Makefile,v 1.14 2008/01/18 05:10:07 tnn Exp $
#

DISTNAME=	x11vnc-0.9.3
PKGREVISION=	1
CATEGORIES=	x11 net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libvncserver/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.karlrunge.com/x11vnc/
COMMENT=	VNC server for real X displays

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-system-libvncserver

PTHREAD_AUTO_VARS=	yes
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread||g'

SUBST_CLASSES+=		libvnc
SUBST_STAGE.libvnc=	post-configure
SUBST_FILES.libvnc=	Makefile
SUBST_SED.libvnc=	-e 's|libvncserver||g'
SUBST_SED.libvnc+=	-e 's|libvncclient||g'

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
