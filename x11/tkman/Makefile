# $NetBSD: Makefile,v 1.21 2000/04/18 06:49:17 fredb Exp $
# FreeBSD Id: Makefile,v 1.28 1997/12/08 15:51:20 tg Exp
#

DISTNAME=		tkman-2.1b2
CATEGORIES=		x11 tk80
MASTER_SITES=		ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org

DEPENDS+=		tk-8.0.5:../../x11/tk80
DEPENDS+=		rman-3.0.*:../../textproc/rman
DEPENDS+=		glimpse-4.1:../../textproc/glimpse

USE_X11=		yes
NO_CDROM=		"Don't sell for profit"
MIRROR_DISTFILE=	no

.include "../../mk/bsd.pkg.mk"
