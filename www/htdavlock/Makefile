# $NetBSD: Makefile,v 1.6 2019/08/22 12:23:52 ryoon Exp $

DISTNAME=	htdavlock-0.2
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	https://ftp.espci.fr/pub/htdavlock/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/htdavlock/
COMMENT=	Apache mod_dav_fs lock database management tool
LICENSE=	original-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
