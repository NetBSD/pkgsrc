# $NetBSD: Makefile,v 1.10 2012/12/06 11:43:52 jperkin Exp $
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

.include "../../mk/bsd.prefs.mk"

post-install:
	${LN} -fs ${PREFIX}/bin/gtime ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/time

.include "../../mk/bsd.pkg.mk"
