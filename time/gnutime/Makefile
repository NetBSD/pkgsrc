# $NetBSD: Makefile,v 1.3 2005/12/05 20:51:08 rillig Exp $
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
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../mk/bsd.pkg.mk"
