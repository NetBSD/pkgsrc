# $NetBSD: Makefile,v 1.5 2003/07/22 04:14:29 martti Exp $

DISTNAME=		CGI-Minimal-1.06
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cgm
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		Perl5 module for simple CGI scripts

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Minimal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
