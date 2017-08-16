# $NetBSD: Makefile,v 1.11 2017/08/16 20:21:16 wiz Exp $
#

DISTNAME=		time-1.7
PKGNAME=		gnu${DISTNAME}
PKGREVISION=		1
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=time/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		https://directory.fsf.org/GNU/time.html
COMMENT=		Report user, system, and real time used by a process
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
INFO_FILES=		yes

CONFIGURE_ARGS+=	--program-prefix=g
INSTALLATION_DIRS=	gnu/bin

.include "../../mk/bsd.prefs.mk"

post-install:
	${LN} -fs ${PREFIX}/bin/gtime ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/time

.include "../../mk/bsd.pkg.mk"
