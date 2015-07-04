# $NetBSD: Makefile,v 1.22 2015/07/04 16:18:40 joerg Exp $
#

DISTNAME=	wmfishtime-1.24
PKGREVISION=	2
CATEGORIES=	time x11
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ne.jp/asahi/linux/timecop/
COMMENT=	Dockable clock application with clock, date and fish

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
