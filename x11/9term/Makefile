# $NetBSD: Makefile,v 1.1.1.1 2000/12/14 00:57:41 wiz Exp $
# FreeBSD Id: Makefile,v 1.5 1996/12/07 23:43:56 asami Exp
#

DISTNAME=		9term.1.6.3
PKGNAME=		9term-1.6.3
CATEGORIES=		plan9 x11
MASTER_SITES=		ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.psrg.cs.usyd.edu.au/~matty/9term/index.html

# needs library and private header, but not during runtime
BUILD_DEPENDS=		${BUILD_ROOT}/editors/sam/${WRKDIR:T}/libframe/libframe.a:../../editors/sam:all

USE_X11=		yes

NOT_FOR_PLATFORM=	*-*-alpha	#LP64 Problems

MANCOMPRESSED=		yes
NO_WRKSUBDIR=		yes
MAKE_ENV+=		WRKDIR=${WRKDIR} PKGSRCDIR=${PKGSRCDIR}

.include "../../mk/bsd.pkg.mk"
