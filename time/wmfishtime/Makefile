# $NetBSD: Makefile,v 1.1.1.1 2001/04/09 06:46:12 kei Exp $
#

DISTNAME=	wmfishtime-1.1
CATEGORIES=	time x11
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ne.jp/asahi/linux/timecop/
COMMENT=	dockable clock application with clock, date and fish

DEPENDS+=	gtk+>=1.2.9:../gtk

USE_X11BASE=	# defined

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/wmfishtime ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
