# $NetBSD: Makefile,v 1.12 2006/09/09 02:46:08 obache Exp $
#

DISTNAME=	robodoc-3.2.3
PKGREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=robodoc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/robodoc/
COMMENT=	Tool to support project documentation within source code

GNU_CONFIGURE=	YES
USE_TOOLS+=	gm4 gmake

SUBST_CLASSES+=		gm4
SUBST_FILES.gm4=	Docs/makefile.in
SUBST_SED.gm4+=		-e 's,@M4@,${TOOLS_M4},g'
SUBST_STAGE.gm4=	post-patch

MAKE_FILE=	makefile

.include "../../mk/bsd.pkg.mk"
