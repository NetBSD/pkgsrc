# $NetBSD: Makefile,v 1.2 2002/10/06 22:31:06 seb Exp $

DISTNAME=      	Time-modules-101.062101
PKGNAME=	p5-${DISTNAME:S/modules-//}
SVR4_PKGNAME=	p5tim
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 functions to convert and use time variables

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Time-modules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
