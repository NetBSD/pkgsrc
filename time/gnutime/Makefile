# $NetBSD: Makefile,v 1.12 2024/04/03 17:25:46 ktnb Exp $
#

DISTNAME=		time-1.9
PKGNAME=		gnu${DISTNAME}
PKGREVISION=		1
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=time/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		https://directory.fsf.org/GNU/time.html
COMMENT=		Report user, system, and real time used by a process
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--program-prefix=g
INSTALLATION_DIRS=	gnu/bin

.include "../../mk/bsd.prefs.mk"

post-install:
	${LN} -fs ${PREFIX}/bin/gtime ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/time

.include "../../mk/bsd.pkg.mk"
