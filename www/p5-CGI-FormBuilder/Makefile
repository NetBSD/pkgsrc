# $NetBSD: Makefile,v 1.8 2005/09/05 14:46:36 abs Exp $

DISTNAME=		CGI-FormBuilder-2.13
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module for building HTML forms

PERL5_PACKLIST=		auto/CGI/FormBuilder/.packlist

DEPENDS+=		p5-HTML-Template>=2.6:../../www/p5-HTML-Template
DEPENDS+=		p5-Text-Template>=1.43:../../textproc/p5-Text-Template
#DEPENDS+=		p5-Template-Toolkit>=2.08:../../www/p5-Template-Toolkit


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
