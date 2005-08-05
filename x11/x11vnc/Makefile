# $NetBSD: Makefile,v 1.1.1.1 2005/08/05 00:08:57 xtraeme Exp $
#

DISTNAME=	x11vnc-0.7.2
CATEGORIES=	x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=libvncserver/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.karlrunge.com/x11vnc/
COMMENT=	VNC server for real X displays

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_header_pthread_h=no # invalid mutex

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
