# $NetBSD: Makefile,v 1.10 1998/08/15 10:07:30 frueauf Exp $
# FreeBSD Id: Makefile,v 1.17 1997/12/08 15:45:27 tg Exp
#

DISTNAME=	rman-3.0.6
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org

CONFLICTS=	rman-3.0.5

RESTRICTED=	"Permission to incorporate this software into commercial products is needed."
NO_CDROM=	"License required"

post-install:
	@strip ${PREFIX}/bin/rman

.include "../../mk/bsd.pkg.mk"
