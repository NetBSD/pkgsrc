# $NetBSD: Makefile,v 1.2 2002/10/07 22:34:27 seb Exp $
#

DISTNAME=      	TimeDate-1.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tid
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 TimeDate distribution

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/TimeDate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
