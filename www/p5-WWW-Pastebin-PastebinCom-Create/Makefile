# $NetBSD: Makefile,v 1.24 2023/07/06 09:43:00 wiz Exp $

DISTNAME=	WWW-Pastebin-PastebinCom-Create-1.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WWW-Pastebin-PastebinCom-Create
COMMENT=	Paste to <http://pastebin.com> from Perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/WWW/Pastebin/PastebinCom/Create/.packlist

DEPENDS+=	p5-URI>=1.35:../../www/p5-URI
# LWP::UserAgent 2.036 is really what is required
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
# for make test
TOOL_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
TOOL_DEPENDS+=	p5-WWW-Mechanize-[0-9]*:../../www/p5-WWW-Mechanize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
