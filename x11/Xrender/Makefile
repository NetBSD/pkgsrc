# $NetBSD: Makefile,v 1.9 2003/10/03 20:11:41 xtraeme Exp $

DISTNAME=	xrender-0.8.3
PKGNAME=	Xrender-0.8.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://pdx.freedesktop.org/software/fontconfig/releases/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Client library for the X Rendering Extension protocol

USE_BUILDLINK2=		YES
USE_X11=		YES
# XXX: LIBTOOL: uses libtool>=1.5 features
#USE_LIBTOOL=		YES
#LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	${WRKSRC}/xrender.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
PLIST_SUBST+=		LIBXRENDER="@comment "
.else
PLIST_SUBST+=		LIBXRENDER=""
.endif

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/render/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
