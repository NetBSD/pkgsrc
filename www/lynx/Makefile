# $NetBSD: Makefile,v 1.15 1998/11/05 02:29:18 mycroft Exp $
#

DISTNAME=       lynx2-8-1
PKGNAME=        lynx-2.8.1
WRKSRC=         ${WRKDIR}/lynx2-8-1
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/release2-8-1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sol.slcc.edu/lynx/

CONFLICTS=	lynx-2.8rel.2 lynx-2.8

DEPENDS+=	libslang-1.2.2:../../devel/libslang

CONFIGURE_ARGS+= --with-screen=slang --with-zlib --libdir="${PREFIX}/etc"
CONFIGURE_ENV+=	LIBS="-lm -ltermcap" CPPFLAGS=-Dunix
GNU_CONFIGURE=  YES

INSTALL_TARGET= install install-help
MAKEFILE=       makefile

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx_help

.include "../../mk/bsd.pkg.mk"
