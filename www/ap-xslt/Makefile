# $NetBSD: Makefile,v 1.7 2002/01/05 21:18:02 jwise Exp $

DISTNAME=	modxslt
PKGNAME=	ap-xslt-1.1nb1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/modxslt/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://modxslt.sourceforge.net/
COMMENT=	Simple, fast XSLT transformations for apache

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
DEPENDS+=	sablotron-*:../../textproc/sablotron

# For "apxs":
BUILD_DEPENDS+= perl>=${PERL5_REQD}:../../lang/perl5

do-install:
		${LOCALBASE}/sbin/apxs -i ${WRKSRC}/mod_xslt.so

.include "../../mk/bsd.pkg.mk"
