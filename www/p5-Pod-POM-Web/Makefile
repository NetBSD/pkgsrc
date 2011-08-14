# $NetBSD: Makefile,v 1.8 2011/08/14 16:06:06 obache Exp $

DISTNAME=	Pod-POM-Web-1.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-POM-Web/
COMMENT=	Perl 5 module providing a HTML Perldoc server
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST= 	auto/Pod/POM/Web/.packlist
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Alien-GvaScript>=1.21:../../www/p5-Alien-GvaScript
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-MIME-Types-[0-9]*:../../mail/p5-MIME-Types
DEPENDS+=	p5-Pod-POM>=0.17:../../textproc/p5-Pod-POM
DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

# recommends
DEPENDS+=       p5-AnnoCPAN-Perldoc-[0-9]*:../../devel/p5-AnnoCPAN-Perldoc
DEPENDS+=       p5-PPI-HTML-[0-9]*:../../textproc/p5-PPI-HTML
DEPENDS+=	p5-Search-Indexer>=0.75:../../textproc/p5-Search-Indexer

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
