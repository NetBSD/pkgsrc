# $NetBSD: Makefile,v 1.9 2006/02/07 11:35:21 abs Exp $

DISTNAME=		CGI-FormBuilder-3.0202
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for building HTML forms
HOMEPAGE=		http://www.formbuilder.org/

PERL5_PACKLIST=		auto/CGI/FormBuilder/.packlist

DEPENDS+=		p5-HTML-Template>=2.6:../../www/p5-HTML-Template
DEPENDS+=		p5-Text-Template>=1.43:../../textproc/p5-Text-Template
#DEPENDS+=		p5-Template-Toolkit>=2.08:../../www/p5-Template-Toolkit


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
