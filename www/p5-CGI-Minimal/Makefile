# $NetBSD: Makefile,v 1.4 2002/09/25 14:45:53 seb Exp $

DISTNAME=		CGI-Minimal-1.06
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cgm
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		perl5 module for simple CGI scripts

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Minimal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
