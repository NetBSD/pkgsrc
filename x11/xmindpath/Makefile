# $NetBSD: Makefile,v 1.15 2009/05/12 21:11:14 zafer Exp $

DISTNAME=	magicpoint-1.09a
PKGNAME=	xmindpath-1.09a
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.riken.go.jp/pub/misc/Japan/MagicPoint/ \
				ftp://ftp.icm.edu.pl/packages/mgp/
				

MAINTAINER=	pkgsrc-users@NetBSD.org
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
