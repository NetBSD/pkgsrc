# $NetBSD: Makefile,v 1.1.1.1 2001/11/13 21:35:26 jlam Exp $

DISTNAME=	quanta-docs-1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quanta/}
EXTRACT_SUFX=	.tar.bz2

QUANTA_DOCS=	css html javascript php
DISTFILES=	# empty
.for DOCS in ${QUANTA_DOCS}
DISTFILES+=	${DOCS}${EXTRACT_SUFX}
.endfor

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://quanta.sourceforge.net/
COMMENT= 	documentation collection for Quanta, the KDE web editor

DEPENDS+=	quanta>=1.9.9.2:../../www/quanta-docs

BUILD_USES_MSGFMT=	YES
USE_BUILDLINK_ONLY=	YES

DIST_SUBDIR=	${PKGBASE}
WRKSRC=		${WRKDIR}
NO_BUILD=	YES

DOCDIR=		${PREFIX}/share/kde/apps/quanta/doc

do-install:
	cd ${WRKSRC};							\
	for dir in ${QUANTA_DOCS}; do					\
		( cd $${dir}; ${CP} -r $${dir} $${dir}.docrc ${DOCDIR} ); \
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}/$${dir};	\
		${CHMOD} -R a-w ${DOCDIR}/$${dir};			\
	done

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
