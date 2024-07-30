# $NetBSD: Makefile,v 1.3 2024/07/30 08:10:19 wiz Exp $

DISTNAME=	1.11.3
PKGNAME=	scdoc-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://git.sr.ht/~sircmpwn/scdoc/archive/
DIST_SUBDIR=	scdoc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~sircmpwn/scdoc/
COMMENT=	Simple man page generator
LICENSE=	mit

WRKSRC=		${WRKDIR}/scdoc-${DISTNAME}

USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	scdoc.pc.in

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fixing man page installation path
SUBST_FILES.man+=	Makefile
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},g"

.include "../../mk/bsd.pkg.mk"
