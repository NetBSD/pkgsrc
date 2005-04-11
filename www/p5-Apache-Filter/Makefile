# $NetBSD: Makefile,v 1.11 2005/04/11 21:47:55 tv Exp $

DISTNAME=	Apache-Filter-1.022
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5afi
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~kwilliams/Apache-Filter-1.022/
COMMENT=	Perl5 module to alter the output of previous Apache handlers

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/Filter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
