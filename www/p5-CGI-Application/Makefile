# $NetBSD: Makefile,v 1.11 2004/04/24 22:46:12 jlam Exp $

DISTNAME=		CGI-Application-2.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cga
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module to create sophisticated, reusable web-based applications

DEPENDS+=		{p5-CGI>=2.66,perl>=5.6.1nb2}:../../www/p5-CGI
DEPENDS+=		p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Application/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
