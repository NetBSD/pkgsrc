# $NetBSD: Makefile,v 1.10 2004/02/09 04:13:06 xtraeme Exp $

DISTNAME=	xrender-0.8.3
PKGNAME=	${DISTNAME:S/X/x/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/software/fontconfig/releases/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Client library for the X Rendering Extension protocol

USE_BUILDLINK3=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	${WRKSRC}/xrender.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/render/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
