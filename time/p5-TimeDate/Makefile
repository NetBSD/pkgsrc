# $NetBSD: Makefile,v 1.6 2003/07/21 17:28:43 martti Exp $
#

DISTNAME=      	TimeDate-1.14
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tid
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 TimeDate distribution

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/TimeDate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
