# $NetBSD: Makefile,v 1.24 2000/01/15 17:37:53 hubertf Exp $
#

DISTNAME=       lynx2-8-2
PKGNAME=        lynx-2.8.2
WRKSRC=         ${WRKDIR}/lynx2-8-2
CATEGORIES=	www
MASTER_SITES=   http://www.slcc.edu/lynx/release2-8-2/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.slcc.edu/lynx/

DEPENDS+=	libslang-*:../../devel/libslang

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

# The patches for this code are from the KAME project:
# ftp://ftp.kame.net/pub/kame/misc/lynx-282-v6-19991008b.diff.gz
.include "../../mk/bsd.prefs.mk"
.if defined(USE_INET6) && ${USE_INET6} == YES
CC+=		-DINET6
PATCHDIR=	${WRKDIR}/.patches
.endif

BUILD_DEFS+=	USE_INET6

INSTALL_TARGET= install install-help
MAKEFILE=       makefile

pre-patch:
.if defined(USE_INET6) && ${USE_INET6} == YES
	${MKDIR} ${WRKDIR}/.patches
	${CP} ${.CURDIR}/patches/patch-* ${WRKDIR}/.patches
	${CP} ${.CURDIR}/patches.v6/patch-* ${WRKDIR}/.patches
.endif

post-install:
	${RM} -rf ${PREFIX}/etc/lynx_doc
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx_help

.include "../../mk/bsd.pkg.mk"
