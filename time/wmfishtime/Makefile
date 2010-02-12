# $NetBSD: Makefile,v 1.19 2010/02/12 00:28:02 joerg Exp $
#

DISTNAME=	wmfishtime-1.24
PKGREVISION=	1
CATEGORIES=	time x11
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ne.jp/asahi/linux/timecop/
COMMENT=	Dockable clock application with clock, date and fish

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
