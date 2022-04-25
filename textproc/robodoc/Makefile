# $NetBSD: Makefile,v 1.20 2022/04/25 10:35:06 tnn Exp $
#

DISTNAME=	robodoc-4.99.6
PKGREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=robodoc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/robodoc/
COMMENT=	Tool to support project documentation within source code

GNU_CONFIGURE=	YES
USE_TOOLS+=	gm4 gmake

MAKE_FILE=	makefile
MAKE_FLAGS+=	docdir=${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
