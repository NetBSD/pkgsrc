# $NetBSD: Makefile,v 1.17 2019/10/12 21:17:09 rillig Exp $
#

DISTNAME=	robodoc-3.2.3
PKGREVISION=	2
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=robodoc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/robodoc/
COMMENT=	Tool to support project documentation within source code

GNU_CONFIGURE=	YES
USE_TOOLS+=	gm4 gmake

SUBST_CLASSES+=		gm4
SUBST_FILES.gm4=	Docs/makefile.in
SUBST_SED.gm4+=		-e 's,@M4@,${TOOLS_M4},g'
SUBST_STAGE.gm4=	pre-configure

MAKE_FILE=	makefile

.include "../../mk/bsd.pkg.mk"
