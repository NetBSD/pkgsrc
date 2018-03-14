# $NetBSD: Makefile,v 1.30 2018/03/14 09:03:24 dholland Exp $

DISTNAME=		swiftsurf-1.2.5
PKGREVISION=		15
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=swiftsurf/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://swiftsurf.sourceforge.net/
COMMENT=		Web proxy that can handle http and https

USE_TOOLS+=		gmake

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
BUILD_TARGET=	nat
SWIFT=		swift.opt
.else
BUILD_TARGET=	byte
SWIFT=		swift
.endif

INSTALLATION_DIRS=	bin share/doc/swiftsurf share/examples/swiftsurf

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	src/conf.ml
SUBST_VARS.conf=	PKG_SYSCONFDIR
SUBST_STAGE.conf=	pre-configure

do-build:
	cd ${WRKSRC}/src && ${GMAKE} ${BUILD_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${SWIFT} ${DESTDIR}${PREFIX}/bin/swiftsurf
	${INSTALL_DATA} ${WRKSRC}/swiftsurf.* ${DESTDIR}${PREFIX}/share/examples/swiftsurf
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/swiftsurf

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
