# $NetBSD: Makefile,v 1.12 2007/10/01 11:09:09 rillig Exp $

DISTNAME=	magicpoint-1.09a
PKGNAME=	xmindpath-1.09a
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.mew.org/pub/MagicPoint/

MAINTAINER=	itojun@itojun.org
COMMENT=	MindPath PocketPoint user-level driver for X11

WRKSRC=		${WRKDIR}/${DISTNAME}/contrib/xmindpath
GNU_CONFIGURE=	yes
USE_FEATURES=	err

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
