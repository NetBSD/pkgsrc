# $NetBSD: Makefile,v 1.6 2004/04/27 05:44:23 snj Exp $

DISTNAME=		CGI-Minimal-1.06
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cgm
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		Perl5 module for simple CGI scripts

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Minimal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
