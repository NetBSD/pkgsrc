# $NetBSD: Makefile,v 1.23 2019/06/30 20:17:35 nia Exp $

DISTNAME=	HTTP-Message-6.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Message
COMMENT=	Construct HTTP style messages
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.00

DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-HTML-Parser>=3.33:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTTP-Date>=6:../../www/p5-HTTP-Date
DEPENDS+=	p5-Encode-Locale>=1.02:../../textproc/p5-Encode-Locale
DEPENDS+=	p5-LWP-MediaTypes>=6.01:../../www/p5-LWP-MediaTypes
DEPENDS+=	p5-IO-HTML-[0-9]*:../../devel/p5-IO-HTML
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

PERL5_PACKLIST=		auto/HTTP/Message/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
