# $NetBSD: Makefile,v 1.67 2018/08/22 09:47:38 wiz Exp $

DISTNAME=		HTML-Parser-3.72
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Parser/
COMMENT=		Perl5 module to parse HTML text documents
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-HTML-Tagset>=3.0:../../www/p5-HTML-Tagset
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
# needed for HTTP/Headers self-test, but this would create a circular
# dependency -- weird.
#DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/HTML/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
