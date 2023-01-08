# $NetBSD: Makefile,v 1.76 2023/01/08 00:01:26 wen Exp $

DISTNAME=		HTML-Parser-3.80
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-Parser
COMMENT=		Perl5 module to parse HTML text documents
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-HTML-Tagset>=3.0:../../www/p5-HTML-Tagset
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
# needed for HTTP/Headers self-test, but this would create a circular
# dependency -- weird.
#DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/HTML/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
