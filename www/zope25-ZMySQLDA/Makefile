# $NetBSD: Makefile,v 1.1.1.1 2002/11/15 12:41:43 drochner Exp $
#

DISTNAME=	ZMySQLDA-2.0.8
PKGNAME=        zope25-ZMySQLDA-2.0.8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mysql-python/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/mysql-python
COMMENT=	MySQL Database adaptor for Zope

USE_BUILDLINK2=	yes

.include "../../www/zope25/product.mk"
.include "../../databases/py-mysqldb/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
