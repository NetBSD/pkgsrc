# $NetBSD: Makefile,v 1.23 2011/03/17 23:32:38 zafer Exp $

DISTNAME=		9term.1.6.3
PKGNAME=		9term-1.6.3
PKGREVISION=		1
CATEGORIES=		plan9 x11
MASTER_SITES=		# ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.psrg.cs.usyd.edu.au/~matty/9term/index.html
COMMENT=		X11 program which emulates a plan9 window

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_DEPMETHOD.sam=	full

NOT_FOR_PLATFORM=	*-*-alpha	#LP64 Problems

WRKSRC=			${WRKDIR}

MANCOMPRESSED=		yes
MAKE_ENV+=		SAM_DIR=${BUILDLINK_PREFIX.sam}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../editors/sam/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
