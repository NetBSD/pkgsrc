# $NetBSD: Makefile,v 1.9 2005/04/02 12:42:28 adrianp Exp $

DISTNAME=      	Time-modules-2003.1126
PKGNAME=	p5-${DISTNAME:S/modules-//}
SVR4_PKGNAME=	p5tim
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 functions to convert and use time variables

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Time-modules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
