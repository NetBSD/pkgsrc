# $NetBSD: Makefile,v 1.8 2001/12/15 20:25:39 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1996/12/07 23:43:56 asami Exp
#

DISTNAME=		9term.1.6.3
PKGNAME=		9term-1.6.3
CATEGORIES=		plan9 x11
MASTER_SITES=		ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.psrg.cs.usyd.edu.au/~matty/9term/index.html
COMMENT=		X11 program which emulates a plan9 window

DEPENDS+=		sam-4.3nb1:../../editors/sam

NOT_FOR_PLATFORM=	*-*-alpha	#LP64 Problems

USE_BUILDLINK_ONLY=	yes

MANCOMPRESSED=		yes
WRKSRC=			${WRKDIR}
MAKE_ENV+=		WRKDIR=${WRKDIR} X11PREFIX=${X11PREFIX}

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
