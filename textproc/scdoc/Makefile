# $NetBSD: Makefile,v 1.2 2022/07/25 11:12:29 wiz Exp $

DISTNAME=	scdoc-1.10.1
CATEGORIES=	textproc
MASTER_SITES=	https://git.sr.ht/~sircmpwn/scdoc/refs/1.10.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~sircmpwn/scdoc/
COMMENT=	Simple man page generator
LICENSE=	mit

USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	scdoc.pc.in

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fixing man page installation path
SUBST_FILES.man+=	Makefile
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},g"

.include "../../mk/bsd.pkg.mk"
