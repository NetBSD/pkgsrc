# $NetBSD: Makefile,v 1.4 2003/07/17 22:56:37 grant Exp $

DISTNAME=	Mowitz-0.2.2
CATEGORIES=	x11
MASTER_SITES=	ftp://siag.nu/pub/mowitz/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://siag.nu/mowitz/
COMMENT=	"More widgets" library

USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
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
