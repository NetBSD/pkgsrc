# $NetBSD: Makefile,v 1.7 2003/07/17 22:56:16 grant Exp $
#

DISTNAME=	ZMySQLDA-2.0.8
PKGNAME=	zope25-ZMySQLDA-2.0.8
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mysql-python/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mysql-python
COMMENT=	MySQL Database adaptor for Zope

USE_BUILDLINK2=	yes
ZOPE_COPYPRODUCT= zope-std-copyproduct-long

.include "../../www/zope25/product.mk"
.include "../../databases/py-mysqldb/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
