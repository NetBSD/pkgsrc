# $NetBSD: Makefile,v 1.2 2005/04/11 21:47:44 tv Exp $
#

DISTNAME=		time-1.7
PKGNAME=		gnu${DISTNAME}
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=time/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnu.org/directory/GNU/time.html
COMMENT=		Report user, system, and real time used by a process

GNU_CONFIGURE=		yes
INFO_FILES=		time.info

CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
PLIST_SUBST+=		GNU_PROGRAM_PREFIX="${GNU_PROGRAM_PREFIX}"
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../mk/bsd.pkg.mk"
