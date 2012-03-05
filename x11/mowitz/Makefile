# $NetBSD: Makefile,v 1.18 2012/03/05 04:28:21 dholland Exp $

DISTNAME=	Mowitz-0.3.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://siag.nu/pub/mowitz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://siag.nu/mowitz/
COMMENT=	"More widgets" library providing X11 widgets

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	XAW_TYPE

.if ${XAW_TYPE} == "xpm"
CONFIGURE_ARGS+=--with-xaw3d=XawXpm
.elif ${XAW_TYPE} == "3d"
CONFIGURE_ARGS+=--with-xaw3d=Xaw3d
.elif ${XAW_TYPE} == "neXtaw"
CONFIGURE_ARGS+=--with-xaw3d=neXtaw
.else
CONFIGURE_ARGS+=--with-xaw3d=Xaw
.endif

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
