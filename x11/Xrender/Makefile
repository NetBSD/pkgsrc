# $NetBSD: Makefile,v 1.26 2005/09/07 16:49:41 reed Exp $

DISTNAME=	libXrender-0.8.4
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Client library for the X Rendering Extension protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	xrender.pc.in

BUILDLINK_DEPENDS.render+=	render>=0.8

.include "../../x11/render/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
