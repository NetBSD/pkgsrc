# $NetBSD: Makefile,v 1.6 2005/12/05 20:51:08 rillig Exp $
#

DISTNAME=	anacron-2.3
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=anacron/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://anacron.sourceforge.net/
COMMENT=	Periodic command scheduler

USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		hdr
SUBST_MESSAGE.hdr=	"Setting up global.h."
SUBST_STAGE.hdr=	pre-configure
SUBST_FILES.hdr=	global.h
.if ${OPSYS} == "NetBSD"
SUBST_SED.hdr=		-e 's|SENDMAIL ".*"|SENDMAIL "/usr/sbin/sendmail"|'
.else
SUBST_SED.hdr=		-e 's|SENDMAIL ".*"|SENDMAIL "/usr/lib/sendmail"|'
.endif

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	"Setting up manpages."
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	anacrontab.5 anacron.8
SUBST_SED.man=		-e 's|/etc/anacrontab|${PKG_SYSCONFDIR}/anacrontab|g'

MAKE_FLAGS+=		ANACRONTAB='${PKG_SYSCONFDIR}/anacrontab'
MAKE_FLAGS+=		BINDIR='${PREFIX}/sbin'
MAKE_FLAGS+=		CFLAGS=${CFLAGS:M*:Q}
MAKE_FLAGS+=		INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=		INSTALL_DIR=${TRUE:Q}
MAKE_FLAGS+=		INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=		MANDIR='${PREFIX}/man'
MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		SHELL=${SH:Q}
MAKE_FLAGS+=		SPOOLDIR='/var/spool/anacron'

EGDIR=			${PREFIX}/share/examples/anacron
.if exists(${FILESDIR}/anacrontab.${OPSYS})
CONF_FILES=		${EGDIR}/anacrontab.${OPSYS} \
			${PKG_SYSCONFDIR}/anacrontab
CONF_FILES_MODE=	0600
.endif

OWN_DIRS=		/var/spool/anacron

RCD_SCRIPTS=		anacron

INSTALLATION_DIRS=	man/man5 man/man8 sbin

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/anacrontab.FreeBSD ${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/anacrontab.NetBSD ${EGDIR}

.include "../../mk/bsd.pkg.mk"
