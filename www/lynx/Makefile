# $NetBSD: Makefile,v 1.21 1999/07/22 07:10:49 mycroft Exp $
#

DISTNAME=       lynx2-8-2
PKGNAME=        lynx-2.8.2
WRKSRC=         ${WRKDIR}/lynx2-8-2
CATEGORIES=	www
MASTER_SITES=   http://www.slcc.edu/lynx/release2-8-2/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.slcc.edu/lynx/

DEPENDS+=	libslang-1.3.8:../../devel/libslang

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
	${RM} -rf ${PREFIX}/etc/lynx_doc
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx_help

.include "../../mk/bsd.pkg.mk"
