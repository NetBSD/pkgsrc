# $NetBSD: Makefile,v 1.8 2009/07/16 13:17:45 zafer Exp $

DISTNAME=		swill-0.3
CATEGORIES=		www devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swill/}
EXTRACT_SUFX=	.tgz

MAINTAINER=		thorpej@NetBSD.org
HOMEPAGE=		http://swill.sourceforge.net/
COMMENT=		The Simple Web Interface Link Library
LICENSE=	gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/SWILL-0.3
GNU_CONFIGURE=		yes
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALLATION_DIRS=	include lib

MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.pkg.mk"
