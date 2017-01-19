# $NetBSD: Makefile,v 1.21 2017/01/19 18:52:30 agc Exp $

DISTNAME=	magicpoint-1.09a
PKGNAME=	xmindpath-1.09a
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.riken.go.jp/pub/misc/Japan/MagicPoint/
MASTER_SITES+=	ftp://ftp.icm.edu.pl/packages/mgp/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MindPath PocketPoint user-level driver for X11

WRKSRC=		${WRKDIR}/${DISTNAME}/contrib/xmindpath
GNU_CONFIGURE=	yes
USE_FEATURES=	err

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
SPECIAL_PERMS=	bin/xmindpath uucp ${REAL_ROOT_GROUP} 4511


.include "../../mk/bsd.prefs.mk"

.if !empty(MISSING_FEATURES:Merr)
pre-build:
	cd ${BUILDLINK_DIR}/include && \
	{ ${ECHO} "#include <nbcompat/cdefs.h>"; \
	  ${ECHO} "#include <stdarg.h>"; \
	  ${ECHO} "#include <nbcompat/err.h>"; \
	} > err.h
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
