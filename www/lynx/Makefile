# $NetBSD: Makefile,v 1.17 1999/02/20 22:48:45 hubertf Exp $
#

DISTNAME=       lynx2-8-1
PKGNAME=        lynx-2.8.1
WRKSRC=         ${WRKDIR}/lynx2-8-1
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/release2-8-1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sol.slcc.edu/lynx/

DEPENDS+=	libslang-1.2.2:../../devel/libslang

GNU_CONFIGURE=  YES
CONFIGURE_ARGS+= --with-screen=slang --with-zlib --libdir="${PREFIX}/etc"
# see if PASSIVE_FETCH is defined in /etc/mk.conf.  If so compile
# with the ftp code set to passive mode (-DNOPORT)
.include "../../mk/bsd.prefs.mk"

.if defined(PASSIVE_FETCH)
CONFIGURE_ENV+=	LIBS="-lm -ltermcap" CPPFLAGS="-Dunix -DNOPORT"
.else
CONFIGURE_ENV+=	LIBS="-lm -ltermcap" CPPFLAGS=-Dunix
.endif

INSTALL_TARGET= install install-help
MAKEFILE=       makefile

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx_help

.include "../../mk/bsd.pkg.mk"
