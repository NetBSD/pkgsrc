# $NetBSD: Makefile,v 1.12 1999/02/20 22:48:44 hubertf Exp $
# FreeBSD Id: Makefile,v 1.17 1997/12/08 15:45:27 tg Exp
#

DISTNAME=	rman-3.0.6
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://http.cs.berkeley.edu/~phelps/tcltk/

RESTRICTED=	"Permission to incorporate this software into commercial products is needed."
NO_CDROM=	"License required"

post-install:
	@strip ${PREFIX}/bin/rman

.include "../../mk/bsd.pkg.mk"
