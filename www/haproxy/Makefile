# $NetBSD: Makefile,v 1.1.1.1 2011/10/31 10:49:31 morr Exp $

DISTNAME=	haproxy-1.4.18
CATEGORIES=	www
MASTER_SITES=	http://haproxy.1wt.eu/download/1.4/src/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://haproxy.1wt.eu/
COMMENT=	Reliable, high performance TCP/HTTP load balancer
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
BUILD_MAKE_FLAGS+=	TARGET=${TARGET}
INSTALL_MAKE_FLAGS+=	TARGET=${TARGET}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/${PKGBASE}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS=	${EGDIR} share/examples/rc.d

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
RCD_SCRIPTS=		haproxy
INSTALLATION_DIRS+=	share/examples/rc.d
.endif

.if ${OPSYS} == "NetBSD"
TARGET=netbsd
.elif ${OPSYS} == "FreeBSD"
TARGET=freebsd
.elif ${OPSYS} == "OpenBSD"
TARGET=openbsd
.elif ${OPSYS} == "Linux"
.  if !empty(OS_VERSION:M2.6.*)
TARGET=linux26
.  elif !empty(OS_VERSION:M2.4.*)
.    if exists(/usr/include/linux/eventpoll.h)
TARGET=linux24e
.    else
TARGET=linux24
.    endif
.  endif
.else
TARGET=generic
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/haproxy.cfg ${DESTDIR}${EGDIR}/

.include "../../mk/bsd.pkg.mk"
