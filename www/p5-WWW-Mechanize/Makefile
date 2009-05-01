# $NetBSD: Makefile,v 1.19 2009/05/01 13:22:57 sno Exp $
#

DISTNAME=	WWW-Mechanize-1.54
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WWW-Mechanize/
COMMENT=	Automates web page form & link interaction
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-libwww>=5.819:../../www/p5-libwww
DEPENDS+=	p5-HTML-Parser>=3.33:../../www/p5-HTML-Parser
DEPENDS+=	p5-URI>=1.36:../../www/p5-URI
DEPENDS+=	p5-Test-Warn>=0.11:../../devel/p5-Test-Warn
DEPENDS+=	p5-HTTP-Response-Encoding>=0.05:../../www/p5-HTTP-Response-Encoding

BUILD_DEPENDS+=	p5-Test-Memory-Cycle-[0-9]*:../../devel/p5-Test-Memory-Cycle
BUILD_DEPENDS+=	p5-Test-Taint-[0-9]*:../../devel/p5-Test-Taint

# use defaults from Makefile.PL, to avoid user interaction
# if not set explicitly
MAKE_PARAMS+=	--mech-dump --nolive

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/WWW/Mechanize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
