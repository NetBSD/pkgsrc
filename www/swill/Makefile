# $NetBSD: Makefile,v 1.7 2009/07/07 18:55:03 joerg Exp $

DISTNAME=		swill-0.1
CATEGORIES=		www devel
MASTER_SITES=		http://systems.cs.uchicago.edu/swill/

MAINTAINER=		thorpej@NetBSD.org
HOMEPAGE=		http://systems.cs.uchicago.edu/swill/
COMMENT=		The Simple Web Interface Link Library

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/SWILL-0.1
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	include lib

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.pkg.mk"
