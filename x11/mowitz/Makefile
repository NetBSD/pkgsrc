# $NetBSD: Makefile,v 1.1.1.1 2003/01/16 05:40:54 uebayasi Exp $

DISTNAME=	Mowitz-0.2.1
CATEGORIES=	x11
MASTER_SITES=	ftp://siag.nu/pub/mowitz/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://siag.nu/mowitz/
COMMENT=	"More widgets" library

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes

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

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
