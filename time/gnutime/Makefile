# $NetBSD: Makefile,v 1.1.1.1 2004/05/27 21:52:45 reed Exp $
#

DISTNAME=		time-1.7
PKGNAME=		gnu${DISTNAME}
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=time/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnu.org/directory/GNU/time.html
COMMENT=		Report user, system, and real time used by a process

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		time.info

CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
PLIST_SUBST+=		GNU_PROGRAM_PREFIX="${GNU_PROGRAM_PREFIX}"
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../mk/bsd.pkg.mk"
