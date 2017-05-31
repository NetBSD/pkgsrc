# $NetBSD: Makefile,v 1.5 2017/05/31 05:22:09 maya Exp $

DISTNAME=		bspwm-0.9.2
CATEGORIES=		wm
MASTER_SITES=		${MASTER_SITE_GITHUB:=baskerville/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		youri@NetBSD.org
HOMEPAGE=		https://github.com/baskerville/bspwm
COMMENT=		Binary space partitioning window manager
LICENSE=		2-clause-bsd

USE_TOOLS+=		gmake bash:run

LDFLAGS.SunOS+=		-lsocket -lnsl

EXAMPLESDIR=		${PREFIX}/share/examples/bspwm
INSTALLATION_DIRS=	share/examples/bspwm

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,share/man,${PKGMANDIR},1'
SUBST_SED.makefile+=	-e 's,examples,examples/*,1'
SUBST_SED.makefile+=	-e 's,$$(DOCPREFIX)"/examples,${EXAMPLESDIR}",1'

.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
