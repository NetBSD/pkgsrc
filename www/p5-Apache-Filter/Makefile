# $NetBSD: Makefile,v 1.4 2002/10/27 20:49:01 seb Exp $

DISTNAME=	Apache-Filter-1.019
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5afi
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module to alter the output of previous Apache handlers

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Filter/.packlist

.include "../../www/ap-perl/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
