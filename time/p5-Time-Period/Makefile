# $NetBSD: Makefile,v 1.1.1.1 2003/05/15 11:52:07 mjl Exp $

DISTNAME=      	Period-1.20
PKGNAME=	p5-Time-${DISTNAME}
SVR4_PKGNAME=	p5per
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PR/PRYAN/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module to deal with time periods

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Time/Period/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
