# $NetBSD: Makefile,v 1.30 2025/02/13 21:09:01 vins Exp $
#

DISTNAME=	xphoon_14Aug2014
PKGNAME=	xphoon-20140814
CATEGORIES=	x11
MASTER_SITES=	https://www.acme.com/software/xphoon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.acme.com/software/xphoon/
COMMENT=	Set the root window to the moon in its current phase
LICENSE=	2-clause-bsd

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
SUBST_CLASSES+=		defs
SUBST_STAGE.defs=	post-configure
SUBST_FILES.defs+=	Makefile
SUBST_SED.defs=		-e 's|-D_BSD_SOURCE[[:space:]]*-D_SVID_SOURCE|-D_DEFAULT_SOURCE|g'
SUBST_MESSAGE.defs=	Replacing deprecated preprocessor-defined macros.
.endif

MAKE_FLAGS+=	CCOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=	LOCAL_LDFLAGS=${LDFLAGS:Q}

WRKSRC=	${WRKDIR}/${PKGBASE}

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
