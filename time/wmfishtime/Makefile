# $NetBSD: Makefile,v 1.14 2005/01/25 04:33:38 tv Exp $
#

DISTNAME=	wmfishtime-1.24
CATEGORIES=	time x11
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ne.jp/asahi/linux/timecop/
COMMENT=	Dockable clock application with clock, date and fish

USE_X11BASE=	# defined
USE_BUILDLINK3=	yes

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
