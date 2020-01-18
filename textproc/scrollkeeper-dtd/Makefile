# $NetBSD: Makefile,v 1.5 2020/01/18 23:35:32 rillig Exp $
#

DISTNAME=	scrollkeeper-omf.dtd
PKGNAME=	scrollkeeper-dtd-1.0
CATEGORIES=	textproc
MASTER_SITES=	http://scrollkeeper.sourceforge.net/dtds/scrollkeeper-omf-1.0/
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scrollkeeper.sourceforge.net/
COMMENT=	DTD from the Scrollkeeper package
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=		# none
NO_BUILD=		yes
INSTALLATION_DIRS=	share/xml
XML_ENTRIES=		public "-//OMF//DTD Scrollkeeper OMF Variant V1.0//EN" \
			${PREFIX}/share/xml/scrollkeeper-omf.dtd

do-install:
	${INSTALL_DATA} ${DISTDIR}/scrollkeeper-omf.dtd \
		${DESTDIR}${PREFIX}/share/xml

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
