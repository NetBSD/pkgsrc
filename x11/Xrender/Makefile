# $NetBSD: Makefile,v 1.21 2004/11/11 17:49:07 sketch Exp $

DISTNAME=	libXrender-0.8.4
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=	.tar.bz2

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
