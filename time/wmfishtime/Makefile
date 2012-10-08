# $NetBSD: Makefile,v 1.21 2012/10/08 13:04:30 asau Exp $
#

DISTNAME=	wmfishtime-1.24
PKGREVISION=	2
CATEGORIES=	time x11
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ne.jp/asahi/linux/timecop/
COMMENT=	Dockable clock application with clock, date and fish

USE_X11BASE=	yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
