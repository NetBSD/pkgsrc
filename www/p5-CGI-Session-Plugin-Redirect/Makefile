# $NetBSD: Makefile,v 1.8 2019/06/30 20:17:22 nia Exp $

DISTNAME=		CGI-Session-Plugin-Redirect-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CGI-Session-Plugin-Redirect
COMMENT=		Perl5 module extension adding a redirect method for CGI::Session
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CGI/Session/Plugin/Redirect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
