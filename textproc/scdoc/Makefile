# $NetBSD: Makefile,v 1.1 2020/03/23 02:29:17 riastradh Exp $

DISTNAME=	scdoc-1.10.1
CATEGORIES=	textproc
MASTER_SITES=	https://git.sr.ht/~sircmpwn/scdoc/refs/1.10.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~sircmpwn/scdoc/
COMMENT=	Simple man page generator
LICENSE=	mit

USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	scdoc.pc.in

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fixing man page installation path
SUBST_FILES.man+=	Makefile
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},g"

.include "../../mk/bsd.pkg.mk"
