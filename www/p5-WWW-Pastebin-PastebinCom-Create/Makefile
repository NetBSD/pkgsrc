# $NetBSD: Makefile,v 1.11 2015/01/12 13:43:06 mef Exp $

DISTNAME=	WWW-Pastebin-PastebinCom-Create-1.003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WWW-Pastebin-PastebinCom-Create/
COMMENT=	Paste to <http://pastebin.com> from Perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/WWW/Pastebin/PastebinCom/Create/.packlist

DEPENDS+=	p5-URI>=1.35:../../www/p5-URI
# LWP::UserAgent 2.036 is really what is required
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
