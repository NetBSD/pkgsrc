# $NetBSD: Makefile,v 1.3 2011/11/02 23:47:37 sbd Exp $

DISTNAME=		cron_4.1
PKGNAME=		vixie-cron-4.1
PKGREVISION=		2
CATEGORIES=		sysutils time
MASTER_SITES=		ftp://ftp.isc.org/isc/cron/
EXTRACT_SUFX=		.shar

MAINTAINER=		reed@reedmedia.net
COMMENT=		Execute and maintain scheduled commands

SPECIAL_PERMS+=		bin/crontab ${SETUID_ROOT_PERMS}
PKG_DESTDIR_SUPPORT=    user-destdir

# Don't extract into WRKDIR because rc.d script is replaced with binary
EXTRACT_CMD=   ${MKDIR} ${WRKSRC} && cd ${WRKSRC} && ${CAT} $$extract_file | ${SH}

RCD_SCRIPTS=		cron

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PKGMANDIR}/man8 sbin
OWN_DIRS+=		${VARBASE}/cron
BUILD_DEFS+=		VARBASE
CPPFLAGS+=		-DCRONDIR=\"${VARBASE:Q}/cron\"

.include "../../mk/bsd.pkg.mk"
