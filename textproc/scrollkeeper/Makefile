# $NetBSD: Makefile,v 1.1.1.1 2001/04/06 10:53:26 rh Exp $
#

DISTNAME=	scrollkeeper-0.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scrollkeeper/}		\
		${MASTER_SITE_GNOME:=stable/sources/scrollkeeper/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://scrollkeeper.sourceforge.net/
COMMENT=	Open Document Cataloging Project

DEPENDS+=	libxml>=1.8.9:../../textproc/libxml

GNU_CONFIGURE=		yes
USE_LIBINTL=		yes
BUILD_USES_MSGFMT=	yes

.include "../../mk/bsd.pkg.mk"
