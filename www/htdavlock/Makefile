# $NetBSD: Makefile,v 1.5 2019/07/20 22:46:55 wiz Exp $

DISTNAME=	htdavlock-0.2
PKGREVISION=	4
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
