# $NetBSD: Makefile,v 1.2 2001/04/09 12:01:07 wiz Exp $
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

.include "../../mk/bsd.pkg.mk"
