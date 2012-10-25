# $NetBSD: Makefile,v 1.2 2012/10/25 06:57:02 asau Exp $
#

DISTNAME=	swath-0.4.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://linux.thai.net/pub/ThaiLinux/software/swath/ 	\
		http://linux.thai.net/pub/ThaiLinux/software/swath/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://linux.thai.net/projects/thailatex
COMMENT=	Smart Word Analysis for THai
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/libdatrie/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
