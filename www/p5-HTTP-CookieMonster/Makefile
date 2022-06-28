# $NetBSD: Makefile,v 1.10 2022/06/28 11:37:27 wiz Exp $

DISTNAME=	HTTP-CookieMonster-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-CookieMonster
COMMENT=	Easy read/write access to your jar of HTTP::Cookies
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTTP-Cookies-[0-9]*:../../www/p5-HTTP-Cookies
DEPENDS+=	p5-Moo>=1.000003:../../devel/p5-Moo
DEPENDS+=	p5-Safe-Isa-[0-9]*:../../devel/p5-Safe-Isa
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

BUILD_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most
BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_PACKLIST=		auto/HTTP/CookieMonster/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
