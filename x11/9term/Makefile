# $NetBSD: Makefile,v 1.9.2.1 2002/06/30 06:24:36 jlam Exp $
# FreeBSD Id: Makefile,v 1.5 1996/12/07 23:43:56 asami Exp
#

DISTNAME=		9term.1.6.3
PKGNAME=		9term-1.6.3
CATEGORIES=		plan9 x11
MASTER_SITES=		ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.psrg.cs.usyd.edu.au/~matty/9term/index.html
COMMENT=		X11 program which emulates a plan9 window

BUILDLINK_DEPMETHOD.sam=	full

NOT_FOR_PLATFORM=	*-*-alpha	#LP64 Problems

USE_BUILDLINK2=		yes
USE_X11=		yes

MANCOMPRESSED=		yes
WRKSRC=			${WRKDIR}
MAKE_ENV+=		SAM_DIR=${BUILDLINK_PREFIX.sam}

.include "../../editors/sam/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
