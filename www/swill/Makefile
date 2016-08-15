# $NetBSD: Makefile,v 1.15 2016/08/15 19:53:52 wiz Exp $

DISTNAME=		swill-0.3
PKGREVISION=		2
CATEGORIES=		www devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=dspinellis/}
GITHUB_TAG=		fafde7646c39bfc3b30521dbcda9efaa94396b0e

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/dspinellis/swill/
COMMENT=		The Simple Web Interface Link Library
LICENSE=		gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-mpi
USE_LIBTOOL=		yes
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

INSTALLATION_DIRS=	include lib

.include "../../mk/bsd.pkg.mk"
