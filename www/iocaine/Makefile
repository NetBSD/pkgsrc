# $NetBSD: Makefile,v 1.1 2026/08/30 14:31:38 leot Exp $

DISTNAME=	iocaine-3.5.1
CATEGORIES=	www
MASTER_SITES=	https://git.madhouse-project.org/iocaine/iocaine/archive/

MAINTAINER=	pkgsrc@gergo.csillger.hu
HOMEPAGE=	https://iocaine.madhouse-project.org/
COMMENT=	AI crawler defense system
LICENSE=	mit

WRKSRC=		${WRKDIR}/iocaine

DEPENDS+=	daemonize>=1.7.8:../../sysutils/daemonize
TEST_DEPENDS+=	bash>5:../../shells/bash
USE_TOOLS+=	paxctl

post-build:
	paxctl +m ${WRKSRC}/target/release/iocaine

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/iocaine \
		${DESTDIR}${PREFIX}/bin/iocaine

do-test:
	set -e; cd ${WRKSRC}; TESTER_BIN=target/release/iocaine ./tests/test_request_handler.sh
	${WRKSRC}/target/release/iocaine --config-path ${WRKSRC}/iocaine-powder/embeds/defaults/testsuite.kdl test suite

.include "cargo-depends.mk"
.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=			VARBASE

IOCAINE_USER?=			iocaine
IOCAINE_GROUP?=			iocaine
IOCAINE_DATADIR=		${VARBASE}/iocaine
IOCAINE_LOGDIR=			${VARBASE}/log/iocaine

PKG_USERS_VARS+=		IOCAINE_USER
PKG_GROUPS_VARS+=		IOCAINE_GROUP
PKG_GROUPS=			${IOCAINE_GROUP}
PKG_USERS=			${IOCAINE_USER}:${IOCAINE_GROUP}
PKG_GECOS.${IOCAINE_USER}=	iocaine
PKG_HOME.${IOCAINE_USER}=	${IOCAINE_DATADIR}
PKG_SHELL.${IOCAINE_USER}=	${NOLOGIN}

PKG_SYSCONFSUBDIR=		iocaine

FILES_SUBST+=			IOCAINE_USER=${IOCAINE_USER:Q}
FILES_SUBST+=			IOCAINE_GROUP=${IOCAINE_GROUP:Q}
FILES_SUBST+=			IOCAINE_DATADIR=${IOCAINE_DATADIR:Q}
FILES_SUBST+=			IOCAINE_LOGDIR=${IOCAINE_LOGDIR:Q}

OWN_DIRS_PERMS+=		${IOCAINE_LOGDIR} ${IOCAINE_USER} ${IOCAINE_GROUP} 0750
OWN_DIRS_PERMS+=		${IOCAINE_DATADIR} ${IOCAINE_USER} ${IOCAINE_GROUP} 0700

EGDIR=				share/examples/iocaine
INSTALLATION_DIRS+=		bin ${EGDIR}

RCD_SCRIPTS+=			iocaine

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
