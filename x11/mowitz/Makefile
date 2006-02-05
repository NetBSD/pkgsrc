# $NetBSD: Makefile,v 1.10 2006/02/05 23:11:40 joerg Exp $

DISTNAME=	Mowitz-0.2.2
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://siag.nu/pub/mowitz/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://siag.nu/mowitz/
COMMENT=	"More widgets" library

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${XAW_TYPE} == "xpm"
CONFIGURE_ARGS+=--with-xawm=XawXpm
.elif ${XAW_TYPE} == "3d"
CONFIGURE_ARGS+=--with-xawm=Xaw3d
.elif ${XAW_TYPE} == "neXtaw"
CONFIGURE_ARGS+=--with-xawm=neXtaw
.else
CONFIGURE_ARGS+=--with-xawm=Xaw
.endif

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
