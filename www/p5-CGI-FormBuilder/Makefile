# $NetBSD: Makefile,v 1.3 2004/12/05 21:04:11 he Exp $

DISTNAME=		CGI-FormBuilder-2.13
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for building HTML forms

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI-FormBuilder/.packlist

DEPENDS+=		p5-HTML-Template>=2.6:../../www/p5-HTML-Template
DEPENDS+=		p5-Text-Template>=1.43:../../textproc/p5-Text-Template
#DEPENDS+=		p5-Template-Toolkit>=2.08:../../www/p5-Template-Toolkit


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
