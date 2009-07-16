# $NetBSD: Makefile,v 1.9 2009/07/16 22:11:41 obache Exp $

DISTNAME=		swill-0.3
CATEGORIES=		www devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=swill/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		thorpej@NetBSD.org
HOMEPAGE=		http://swill.sourceforge.net/
COMMENT=		The Simple Web Interface Link Library
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/SWILL-0.3
GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
