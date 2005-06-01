# $NetBSD: Makefile,v 1.18 2005/06/01 18:03:27 jlam Exp $

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

MANCOMPRESSED=		yes
MAKE_ENV+=		SAM_DIR=${BUILDLINK_PREFIX.sam}

.include "../../editors/sam/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
