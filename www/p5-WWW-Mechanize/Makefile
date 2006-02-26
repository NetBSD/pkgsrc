# $NetBSD: Makefile,v 1.10 2006/02/26 09:09:05 wiz Exp $
#

DISTNAME=	WWW-Mechanize-1.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://search.cpan.org/dist/WWW-Mechanize/
COMMENT=	Automates web page form & link interaction

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww
DEPENDS+=	p5-HTML-Parser>=3.35:../../www/p5-HTML-Parser
DEPENDS+=	p5-URI>=1.30:../../www/p5-URI
DEPENDS+=	p5-Test-LongString>=0:../../devel/p5-Test-LongString

# use defaults from Makefile.PL, to avoid user interaction
# if not set explicitly
MAKE_PARAMS+=	--mech-dump --nolive

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/WWW/Mechanize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
