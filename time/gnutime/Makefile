# $NetBSD: Makefile,v 1.7 2009/07/07 20:21:37 joerg Exp $
#

DISTNAME=		time-1.7
PKGNAME=		gnu${DISTNAME}
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=time/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://directory.fsf.org/GNU/time.html
COMMENT=		Report user, system, and real time used by a process

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../mk/bsd.pkg.mk"
