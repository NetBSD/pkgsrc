# $NetBSD: Makefile,v 1.8 2002/07/02 11:42:39 agc Exp $
#

DISTNAME=		openacs-3.2.5
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		# none
EXTRACT_SUFX=		.tgz

MAINTAINER=		cjones@netbsd.org
HOMEPAGE=		http://www.openacs.org/
COMMENT=		TCL-based web programming environment

# Would also work with AOLServer, but there's no package for that.
DEPENDS+=		ap-aolserver-1.1:../../www/ap-aolserver
DEPENDS+=		postgresql-lib>=7.0:../../databases/postgresql-lib
DEPENDS+=		ImageMagick>=5.3.9nb1:../../graphics/ImageMagick
DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
BUILD_DEPENDS+=		postgresql-client>=7.0:../../databases/postgresql-client

INTERACTIVE_STAGE=	fetch

NO_CONFIGURE=	# set
NO_BUILD=	# set

MESSAGE_SUBST+=	PREFIX=${PREFIX}

_FETCH_MESSAGE= \
	    ${ECHO} "==============================================================="; \
	    ${ECHO} "Please fetch ${DISTFILES} into ${DISTDIR}" ; \
	    ${ECHO} "from ${HOMEPAGE} ." ; \
	    ${ECHO} "==============================================================="

SEDFILES=${WRKSRC}/parameters/ad.tcl \
	${WRKSRC}/bin/aolserver-errors.pl \
	${WRKSRC}/bin/queue-message.pl \
	${WRKSRC}/www/doc/sql/postgres.sql \
	${WRKDIR}/install-openacs
# This intentionally clobbers the .orig files:
post-patch:
	${CP} ${FILESDIR}/install-openacs ${WRKDIR}
	for F in ${SEDFILES} ; do \
	${SED} "s,@PREFIX@,${PREFIX},g" < $$F > $$F.orig ; \
	${MV} $$F.orig $$F ; \
	done

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/install-openacs ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/openacs
	( cd ${WRKSRC} ; tar cf - . ) | \
		( cd ${PREFIX}/share/openacs ; tar xf - )

.include "../../mk/bsd.pkg.mk"
