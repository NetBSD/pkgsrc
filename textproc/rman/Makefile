# $NetBSD: Makefile,v 1.7 1998/04/20 11:56:34 frueauf Exp $
# FreeBSD Id: Makefile,v 1.17 1997/12/08 15:45:27 tg Exp
#

DISTNAME=		rman-3.0.4
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org

NO_CDROM=		"License required"
MIRROR_DISTFILE=	no
MAN1=			rman.1

post-install:
	@strip ${PREFIX}/bin/rman

.include "../../mk/bsd.pkg.mk"
