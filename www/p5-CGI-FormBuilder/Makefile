# $NetBSD: Makefile,v 1.2 2004/04/27 05:44:23 snj Exp $

DISTNAME=		CGI-FormBuilder-2.12
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for building HTML forms

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI-FormBuilder/.packlist

DEPENDS+=		p5-HTML-Template>=2.6:../../www/p5-HTML-Template

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
