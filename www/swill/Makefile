# $NetBSD: Makefile,v 1.16 2026/08/04 20:29:20 wiz Exp $

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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
