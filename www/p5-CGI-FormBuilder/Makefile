# $NetBSD: Makefile,v 1.1.1.1 2003/12/04 15:32:27 grant Exp $

DISTNAME=		CGI-FormBuilder-2.12
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for building HTML forms

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI-FormBuilder/.packlist

DEPENDS+=		p5-HTML-Template>=2.6:../../www/p5-HTML-Template

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
