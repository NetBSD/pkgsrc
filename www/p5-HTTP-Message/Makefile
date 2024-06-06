# $NetBSD: Makefile,v 1.40 2024/06/06 07:36:24 wiz Exp $

DISTNAME=	HTTP-Message-6.46
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Message
COMMENT=	Construct HTTP style messages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Clone>=0.46:../../devel/p5-Clone
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-HTTP-Date>=6:../../www/p5-HTTP-Date
DEPENDS+=	p5-Encode-Locale>=1.02:../../textproc/p5-Encode-Locale
DEPENDS+=	p5-LWP-MediaTypes>=6.01:../../www/p5-LWP-MediaTypes
DEPENDS+=	p5-IO-HTML-[0-9]*:../../devel/p5-IO-HTML
TEST_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs

CONFLICTS+=	p5-libwww<6.00

PERL5_PACKLIST=		auto/HTTP/Message/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
