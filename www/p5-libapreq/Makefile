# $NetBSD: Makefile,v 1.5 2003/09/06 03:42:29 kim Exp $

DISTNAME=	libapreq-1.2
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lap
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/libapreq/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
