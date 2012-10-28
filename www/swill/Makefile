# $NetBSD: Makefile,v 1.13 2012/10/28 06:31:06 asau Exp $

DISTNAME=		swill-0.3
PKGREVISION=		1
CATEGORIES=		www devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=swill/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://swill.sourceforge.net/
COMMENT=		The Simple Web Interface Link Library
LICENSE=		gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/SWILL-0.3
GNU_CONFIGURE=		yes
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
