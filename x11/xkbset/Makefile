# $NetBSD: Makefile,v 1.24 2019/08/11 13:25:20 wiz Exp $
#

DISTNAME=	xkbset-0.5
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://faculty.missouri.edu/~stephen/software/xkbset/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://faculty.missouri.edu/~stephen/software/#xkbset
COMMENT=	Manages XKB features of the X window system

USE_TOOLS+=	perl:run
REPLACE_PERL=	xkbset-gui

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
