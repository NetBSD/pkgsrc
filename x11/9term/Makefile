# $NetBSD: Makefile,v 1.16 2005/03/24 21:13:03 wiz Exp $

DISTNAME=		9term.1.6.3
PKGNAME=		9term-1.6.3
CATEGORIES=		plan9 x11
MASTER_SITES=		ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.psrg.cs.usyd.edu.au/~matty/9term/index.html
COMMENT=		X11 program which emulates a plan9 window

BUILDLINK_DEPMETHOD.sam=	full

NOT_FOR_PLATFORM=	*-*-alpha	#LP64 Problems

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		yes
USE_X11=		yes

MANCOMPRESSED=		yes
MAKE_ENV+=		SAM_DIR=${BUILDLINK_PREFIX.sam}

.include "../../editors/sam/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
