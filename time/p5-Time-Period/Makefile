# $NetBSD: Makefile,v 1.5 2004/04/11 16:49:23 snj Exp $

DISTNAME=      	Period-1.20
PKGNAME=	p5-Time-${DISTNAME}
SVR4_PKGNAME=	p5per
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PR/PRYAN/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to deal with time periods

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Time/Period/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
