# $NetBSD: Makefile,v 1.5 2003/05/02 11:57:33 wiz Exp $

DISTNAME=		Xdialog-1.4.6
PKGREVISION=		1
PKGNAME=		xdialog-1.4.6
CATEGORIES=		misc x11
MASTER_SITES=		http://xdialog.free.fr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://xdialog.free.fr/
COMMENT=		X11 drop-in replacement for the curses dialog program

DEPENDS+=		gtk+>=1.2.10nb4:../../x11/gtk

USE_X11BASE=		# defined
USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined

.include "../../mk/bsd.pkg.mk"
