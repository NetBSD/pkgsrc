# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:44 tv Exp $

DISTNAME=      	Time-modules-2003.1126
PKGNAME=	p5-${DISTNAME:S/modules-//}
SVR4_PKGNAME=	p5tim
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 functions to convert and use time variables

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Time-modules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
