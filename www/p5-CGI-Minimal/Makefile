# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:56 tv Exp $

DISTNAME=		CGI-Minimal-1.16
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cgm
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Minimal/
COMMENT=		Perl5 module for simple CGI scripts

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Minimal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
