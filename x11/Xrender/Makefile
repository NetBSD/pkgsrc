# $NetBSD: Makefile,v 1.17 2004/04/24 22:46:13 jlam Exp $

DISTNAME=	xrender-0.8.3
PKGNAME=	${DISTNAME:S/x/X/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/software/fontconfig/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Client library for the X Rendering Extension protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	xrender.pc.in

BUILDLINK_DEPENDS.render+=	render>=0.8

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/render/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
