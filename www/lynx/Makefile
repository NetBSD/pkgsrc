# $NetBSD: Makefile,v 1.14 1998/10/04 22:05:42 tv Exp $
#

DISTNAME=       lynx2-8
PKGNAME=        lynx-2.8
WRKSRC=         ${WRKDIR}/lynx2-8
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/release2-8/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sol.slcc.edu/lynx/

CONFLICTS=	lynx-2.8rel.2

DEPENDS+=	libslang-1.2.2:../../devel/libslang

CONFIGURE_ARGS+= --with-screen=slang --with-zlib --libdir="${PREFIX}/etc"
CONFIGURE_ENV+=	LIBS="-lm -ltermcap" CPPFLAGS=-Dunix
GNU_CONFIGURE=  YES

INSTALL_TARGET= install install-help
MAKEFILE=       makefile

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx_help

.include "../../mk/bsd.pkg.mk"
