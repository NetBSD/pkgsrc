# $NetBSD: Makefile,v 1.10 1998/04/20 11:56:36 frueauf Exp $
# FreeBSD Id: Makefile,v 1.28 1997/12/08 15:51:20 tg Exp
#

DISTNAME=		tkman-2.0.4
CATEGORIES=		misc tk80
MASTER_SITES=		ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org

LIB_DEPENDS=		tk80.1.:${PORTSDIR}/x11/tk80
RUN_DEPENDS=		rman:${PORTSDIR}/textproc/rman \
			glimpse:${PORTSDIR}/textproc/glimpse

NO_CDROM=		"Don't sell for profit"
MIRROR_DISTFILE=	no

.include "../../mk/bsd.pkg.mk"
