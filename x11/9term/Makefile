# $NetBSD: Makefile,v 1.4 2001/04/02 18:46:38 wiz Exp $
# FreeBSD Id: Makefile,v 1.5 1996/12/07 23:43:56 asami Exp
#

DISTNAME=		9term.1.6.3
PKGNAME=		9term-1.6.3
CATEGORIES=		plan9 x11
MASTER_SITES=		ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.psrg.cs.usyd.edu.au/~matty/9term/index.html
COMMENT=		X11 program which emulates a plan9 window

USE_X11=		yes

NOT_FOR_PLATFORM=	*-*-alpha	#LP64 Problems

MANCOMPRESSED=		yes
NO_WRKSUBDIR=		yes
MAKE_ENV+=		WRKDIR=${WRKDIR} PKGSRCDIR=${PKGSRCDIR}

pre-configure:
	if [ ! -e ${BUILD_ROOT}/editors/sam/${WRKDIR:T}/libframe/libframe.a ]; then \
		cd ../../editors/sam && ${MAKE} all;			\
	fi

pre-clean:
	cd ../../editors/sam && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
