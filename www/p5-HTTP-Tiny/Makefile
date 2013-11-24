# $NetBSD: Makefile,v 1.8 2013/11/24 00:35:07 wen Exp $
#

DISTNAME=	HTTP-Tiny-0.038
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Tiny/
COMMENT=	Perl5 module providing a small, simple, correct HTTP/1.1 client
LICENSE=	${PERL5_LICENSE}

# used for test
DEPENDS+=	p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Mozilla-CA>=0:../../security/p5-Mozilla-CA

PERL5_PACKLIST=		auto/HTTP/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
