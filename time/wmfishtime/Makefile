# $NetBSD: Makefile,v 1.4 2002/01/19 08:38:41 taca Exp $
#

DISTNAME=	wmfishtime-1.23
CATEGORIES=	time x11
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ne.jp/asahi/linux/timecop/
COMMENT=	dockable clock application with clock, date and fish

DEPENDS+=	gtk+>=1.2.9:../../x11/gtk

USE_X11BASE=	# defined

MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" INSTALL_MAN="${INSTALL_MAN}"

.include "../../mk/bsd.pkg.mk"
