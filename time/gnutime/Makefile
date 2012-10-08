# $NetBSD: Makefile,v 1.9 2012/10/08 13:04:18 asau Exp $
#

DISTNAME=		time-1.7
PKGNAME=		gnu${DISTNAME}
PKGREVISION=		1
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=time/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://directory.fsf.org/GNU/time.html
COMMENT=		Report user, system, and real time used by a process
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
INFO_FILES=		yes

CONFIGURE_ARGS+=	--program-prefix=g
INSTALLATION_DIRS=	gnu/bin

post-install:
	ln -f -s ../../bin/gtime ${DESTDIR}${PREFIX}/gnu/bin/time

.include "../../mk/bsd.pkg.mk"
