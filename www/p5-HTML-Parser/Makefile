# $NetBSD: Makefile,v 1.82 2025/07/04 08:49:11 wiz Exp $

DISTNAME=		HTML-Parser-3.83
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-Parser
COMMENT=		Perl5 module to parse HTML text documents
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-HTML-Tagset>=3.0:../../www/p5-HTML-Tagset
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=		p5-HTTP-Message>=6.45nb1:../../www/p5-HTTP-Message

PERL5_PACKLIST=		auto/HTML/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
