# $NetBSD: Makefile,v 1.22 2000/08/18 22:46:52 hubertf Exp $
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

RESTRICTED=		"Don't sell for profit"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
