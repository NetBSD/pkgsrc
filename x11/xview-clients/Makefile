# $NetBSD: Makefile,v 1.41 2022/04/23 00:15:46 gutteridge Exp $

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-clients-3.2.1
PKGREVISION=		5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		OpenLook applications and man pages

MAKE_JOBS_SAFE=		no

BROKEN_ON_PLATFORM=	${LP64PLATFORMS}  # It builds but everything segfaults.

LICENSE=		sun-openlook-license
NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	${DISTNAME}/clients ${DISTNAME}/images

WRKSRC=			${WRKDIR}/${DISTNAME}/clients
USE_IMAKE=		yes

SUBST_CLASSES+=		xvc
SUBST_STAGE.xvc=	pre-configure
SUBST_MESSAGE.xvc=	Fixing hard-coded paths.
SUBST_FILES.xvc=	olwm/openwin-menu-programs
SUBST_VARS.xvc=		PREFIX
SUBST_VARS.xvc+=	X11BASE

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
MAKE_FLAGS+=		CCOPTIONS=-Wno-error=return-type
.endif

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xview-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
