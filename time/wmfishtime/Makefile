# $NetBSD: Makefile,v 1.2 2001/04/14 20:35:09 dmcmahill Exp $
#

DISTNAME=	wmfishtime-1.1
CATEGORIES=	time x11
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ne.jp/asahi/linux/timecop/
COMMENT=	dockable clock application with clock, date and fish

DEPENDS+=	gtk+>=1.2.9:../../x11/gtk

USE_X11BASE=	# defined

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/wmfishtime ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
