# $NetBSD: Makefile,v 1.10 2002/09/10 16:06:51 wiz Exp $

DISTNAME=	modxslt
PKGNAME=	ap-xslt-1.1
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/modxslt/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://modxslt.sourceforge.net/
COMMENT=	Simple, fast XSLT transformations for apache

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
DEPENDS+=	sablotron>=0.71nb1:../../textproc/sablotron

USE_PERL5=	build	# for "apxs"

do-install:
		${LOCALBASE}/sbin/apxs -i ${WRKSRC}/mod_xslt.so

.include "../../mk/bsd.pkg.mk"
