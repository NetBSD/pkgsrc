# $NetBSD: Makefile,v 1.1.1.1 2003/01/10 19:24:48 jmmv Exp $
#

DISTNAME=	xmlcatmgr-0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlcatmgr/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://www.sourceforge.net/projects/xmlcatmgr/
COMMENT=	XML catalog manager

USE_BUILDLINK2=	YES

MAKEFILE=	Makefile.boot
MAKE_ENV+=	BT_PREFIX="${PREFIX}"
MAKE_ENV+=	BT_PROG_AWK="${AWK}"
MAKE_ENV+=	BT_PROG_SH="${SH}"
MAKE_ENV+=	BT_DIR_CATALOG="${PREFIX}/share/xml"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xml
	${PREFIX}/bin/xmlcatmgr create

.include "../../mk/bsd.pkg.mk"
