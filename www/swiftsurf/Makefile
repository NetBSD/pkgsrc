# $NetBSD: Makefile,v 1.1.1.1 2003/06/29 23:15:07 jtb Exp $

DISTNAME=		swiftsurf-1.2.5
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=swiftsurf/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://swiftsurf.sourceforge.net
COMMENT=		web proxy that can handle http and https

BUILD_DEPENDS=		ocaml>=3.00:../../lang/ocaml

USE_BUILDLINK2=		yes
USE_GMAKE=		yes

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
ALL_TARGET=	nat
SWIFT=		swift.opt
.else
ALL_TARGET=	byte
SWIFT=		swift
.endif

do-configure:
	for f in ${WRKSRC}/src/conf.ml; do \
		${SED} -e 's:@PKG_SYSCONFDIR@:${PKG_SYSCONFDIR}:g' \
		$$f > $$f.tmp && ${MV} $$f.tmp $$f; \
	done

do-build:
	cd ${WRKSRC}/src && ${GMAKE} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${SWIFT} ${PREFIX}/bin/swiftsurf
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/swiftsurf
	${INSTALL_DATA} ${WRKSRC}/swiftsurf.* ${PREFIX}/share/examples/swiftsurf
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/swiftsurf
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/swiftsurf

.include "../../mk/bsd.pkg.mk"
