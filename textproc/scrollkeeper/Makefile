# $NetBSD: Makefile,v 1.3 2001/05/02 12:37:05 rh Exp $
#

DISTNAME=	scrollkeeper-0.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scrollkeeper/}		\
		${MASTER_SITE_GNOME:=stable/sources/scrollkeeper/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://scrollkeeper.sourceforge.net/
COMMENT=	Open Document Cataloging Project

BUILD_USES_MSGFMT=	yes
DEPENDS+=	libxml>=1.8.9:../../textproc/libxml

GNU_CONFIGURE=		yes
USE_LIBINTL=		yes
USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
