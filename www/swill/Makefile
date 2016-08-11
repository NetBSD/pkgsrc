# $NetBSD: Makefile,v 1.14 2016/08/11 12:51:15 schmonz Exp $

GITHUB_PROJECT=		swill
DISTNAME=		fafde7646c39bfc3b30521dbcda9efaa94396b0e
PKGNAME=		swill-0.3
PKGREVISION=		2
CATEGORIES=		www devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=dspinellis/}
DIST_SUBDIR=		${GITHUB_PROJECT}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/dspinellis/swill/
COMMENT=		The Simple Web Interface Link Library
LICENSE=		gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-mpi
USE_LIBTOOL=		yes
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

INSTALLATION_DIRS=	include lib

.include "../../mk/bsd.pkg.mk"
