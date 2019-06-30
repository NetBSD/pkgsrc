# $NetBSD: Makefile,v 1.13 2019/06/30 20:17:35 nia Exp $

DISTNAME=	HTTP-Parser-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Parser
COMMENT=	Perl 5 module to parse HTTP request into HTTP::Request/Response object
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/HTTP/Parser/.packlist

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
