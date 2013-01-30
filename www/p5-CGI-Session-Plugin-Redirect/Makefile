# $NetBSD: Makefile,v 1.1 2013/01/30 18:51:40 wiz Exp $

DISTNAME=		CGI-Session-Plugin-Redirect-1.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Session-Plugin-Redirect/
COMMENT=		Perl5 module extension adding a redirect method for CGI::Session
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CGI/Session/Plugin/Redirect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
