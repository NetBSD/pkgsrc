# $NetBSD: Makefile,v 1.14 1998/09/08 14:55:22 agc Exp $
# FreeBSD Id: Makefile,v 1.28 1997/12/08 15:51:20 tg Exp
#

DISTNAME=		tkman-2.1b1
CATEGORIES=		misc tk80
MASTER_SITES=		ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org

DEPENDS+=		tk-8.0p2:../../x11/tk80
RUN_DEPENDS=		rman:../../textproc/rman \
			glimpse:../../textproc/glimpse

NO_CDROM=		"Don't sell for profit"
MIRROR_DISTFILE=	no

.include "../../mk/bsd.pkg.mk"
