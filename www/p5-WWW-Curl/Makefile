# $NetBSD: Makefile,v 1.1.1.1 2005/01/08 13:18:55 minskim Exp $
#

DISTNAME=	WWW-Curl-2.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://curl.haxx.se/libcurl/perl/
COMMENT=	Perl binding interface for curl

DEPENDS+=	curl>=7.12.1:../../www/curl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/WWW/Curl/.packlist

.include "../../www/curl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
