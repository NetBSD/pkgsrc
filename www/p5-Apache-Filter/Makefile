# $NetBSD: Makefile,v 1.7 2003/07/22 04:14:27 martti Exp $

DISTNAME=	Apache-Filter-1.019
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5afi
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to alter the output of previous Apache handlers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Filter/.packlist

.include "../../www/ap-perl/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
