# $NetBSD: Makefile,v 1.13 2007/10/01 11:59:59 rillig Exp $

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

.include "../../mk/bsd.prefs.mk"

.if !empty(MISSING_FEATURES:Merr)
pre-build:
	cd ${BUILDLINK_DIR}/include && \
	{ echo "#include <nbcompat/cdefs.h>"; \
	  echo "#include <stdarg.h>"; \
	  echo "#include <nbcompat/err.h>"; \
	} > err.h
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
