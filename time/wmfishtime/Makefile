# $NetBSD: Makefile,v 1.23 2020/01/26 17:32:19 rillig Exp $
#

DISTNAME=	wmfishtime-1.24
PKGREVISION=	2
CATEGORIES=	time x11
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ne.jp/asahi/linux/timecop/
COMMENT=	Dockable clock application with clock, date and fish

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
