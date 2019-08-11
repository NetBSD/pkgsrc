# $NetBSD: Makefile,v 1.13 2019/08/11 13:24:43 wiz Exp $
#

DISTNAME=	HTML-WikiConverter-DokuWiki-0.53
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/release/DIBERRI/HTML-WikiConverter-DokuWiki-0.53/lib/HTML/WikiConverter/DokuWiki.pm
COMMENT=	DokuWiki dialect module for converting HTML to wiki markup

DEPENDS+=	p5-HTML-WikiConverter>=0.63:../../www/p5-HTML-WikiConverter

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/WikiConverter/DokuWiki/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
