# $NetBSD: Makefile,v 1.4 2002/10/27 20:49:00 seb Exp $

DISTNAME=	libapreq-0.33
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lap
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://trainedmonkey.com/
COMMENT=	Lots of Apache specific httpd handling modules

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/libapreq/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
